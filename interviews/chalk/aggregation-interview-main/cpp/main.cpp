#include "aggregates.cpp"

#include <cstdint>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <chrono>
#include <unordered_map>

/*
EXAMPLE DOMAIN: Merchants and Customers

We live in a world with merchants and customers, where customers make orders
to these merchants. Each record the aggregator receives comes with the following fields:

- merchant_id: int
- customer_id: int
- amount: float
*/

struct Record {
    std::unordered_map<std::string, int> values;
    std::chrono::system_clock::time_point ts;
};

std::chrono::hours days(int count) {
    return std::chrono::hours(24LL * count);
}

template <typename T>
std::string optional_to_string(std::optional<T> opt) {
    if (opt.has_value()) {
        return std::to_string(*opt);
    } else {
        return "nullopt";
    }
}

// Fixes current time so that the tests are deterministic and query start and
// end times fall on bucket boundaries if buckets are constructed such that their boundaries
// align with the Unix epoch.
const auto now =
    std::chrono::system_clock::time_point{std::chrono::seconds{1775001600}};

void test_part1_example() {
    AggregationConfig config(
        "merchant_sales",
        {"merchant_id"},
        AggregationType::MEAN,
        std::nullopt,
        "amount"
    );

    Aggregator aggregator(config);

    aggregator.add_record(
        {{"merchant_id", 1}, {"customer_id", 1}, {"amount", 100}}, now - days(1)
    );

    aggregator.add_record(
        {{"merchant_id", 1}, {"customer_id", 2}, {"amount", 200}}, now - days(3)
    );

    aggregator.add_record(
        {{"merchant_id", 2}, {"customer_id", 1}, {"amount", 300}}, now - days(7)
    );

    aggregator.add_record(
        {{"merchant_id", 2}, {"customer_id", 2}, {"amount", 400}}, now - days(2)
    );

    aggregator.add_record(
        {{"merchant_id", 2}, {"customer_id", 2}, {"amount", 500}}, now - days(5)
    );

    // note that ts doesn't matter in this part
    auto test1 = aggregator.query_agg({{"merchant_id", 1}});
    if (!test1 || *test1 != 150) {
        throw std::runtime_error("Expected 150, got " + optional_to_string(test1));
    }

    auto test2 = aggregator.query_agg({{"merchant_id", 2}});
    if (!test2 || *test2 != 400) {
        throw std::runtime_error("Expected 400, got " + optional_to_string(test2));
    }
}

void test_part2_example() {
    AggregationConfig config(
        "merchant_sales_with_time",
        {"merchant_id"},
        AggregationType::MEAN,
        std::chrono::duration_cast<std::chrono::milliseconds>(days(2)),
        "amount"
    );

    Aggregator aggregator(config);

    aggregator.add_record(
        {{"merchant_id", 1}, {"customer_id", 1}, {"amount", 100}}, now - days(1)
    );

    aggregator.add_record(
        {{"merchant_id", 1}, {"customer_id", 2}, {"amount", 200}}, now - days(3)
    );

    aggregator.add_record(
        {{"merchant_id", 2}, {"customer_id", 1}, {"amount", 300}},
        now - std::chrono::hours(12)
    );

    aggregator.add_record(
        {{"merchant_id", 2}, {"customer_id", 2}, {"amount", 400}}, now - days(5)
    );

    aggregator.add_record(
        {{"merchant_id", 2}, {"customer_id", 2}, {"amount", 500}}, now - days(7)
    );

    auto test1 = aggregator.query_agg(
        {{"merchant_id", 1}},
        now - days(2),
        now
    );
    if (!test1 || *test1 != 100) {
        throw std::runtime_error("Expected 100, got " + optional_to_string(test1));
    }

    auto test2 = aggregator.query_agg(
        {{"merchant_id", 1}},
        now - days(14),
        now
    );
    if (!test2 || *test2 != 150) {
        throw std::runtime_error("Expected 150, got " + optional_to_string(test2));
    }

    auto test3 = aggregator.query_agg(
        {{"merchant_id", 2}},
        now - days(6),
        now
    );
    if (!test3 || *test3 != 350) {
        throw std::runtime_error("Expected 350, got " + optional_to_string(test3));
    }

    auto test4 = aggregator.query_agg(
        {{"merchant_id", 2}},
        now - days(6),
        now - days(4)
    );
    if (!test4 || *test4 != 400) {
        throw std::runtime_error("Expected 400, got " + optional_to_string(test4));
    }
}

// Sample records to be added to aggregators
const std::vector<Record> sample_records = {
    {
        {{"merchant_id", 1}, {"customer_id", 1}, {"amount", 100}},
        now - days(1)  // 1 day ago
    },
    {
        {{"merchant_id", 1}, {"customer_id", 2}, {"amount", 900}},
        now - std::chrono::hours(6)  // 6 hours ago
    },
    {
        {{"merchant_id", 2}, {"customer_id", 1}, {"amount", 200}},
        now - days(3)  // 3 days ago
    },
    {
        {{"merchant_id", 2}, {"customer_id", 2}, {"amount", 500}},
        now - days(3)  // 3 days ago
    },
    {
        {{"merchant_id", 2}, {"customer_id", 2}, {"amount", 700}},
        now - days(7)  // 7 days ago
    }
};

void test_part1_order_count_all_time() {
    // Count aggregation with single group_by_columns field, over all time
    // Example: "Given a merchant id, I want to know their total number of orders ever."
    AggregationConfig order_count_agg(
        "order_count_all_time",
        {"merchant_id"},
        AggregationType::COUNT,
        std::nullopt,  // all time
        std::nullopt   // Count doesn't need a field
    );

    Aggregator aggregator(order_count_agg);
    for (const auto& record : sample_records) {
        aggregator.add_record(record.values, record.ts);
    }

    // Query without start/end - returns count over all time
    auto test1 = aggregator.query_agg({{"merchant_id", 1}});
    if (!test1 || *test1 != 2) {
        throw std::runtime_error("Expected 2, got " + optional_to_string(test1));
    }

    auto test2 = aggregator.query_agg({{"merchant_id", 2}});
    if (!test2 || *test2 != 3) {
        throw std::runtime_error("Expected 3, got " + optional_to_string(test2));
    }

    auto test3 = aggregator.query_agg({{"merchant_id", 3}});
    if (test3.has_value()) {
        throw std::runtime_error("Expected nullopt, got " + std::to_string(*test3));
    }
}

void test_part1_customer_spend_per_merchant_all_time() {
    // Sum aggregation with multiple group_by_columns fields, over all time
    // Example: "Given a customer-merchant pair, I want to know the total amount
    // that customer spent at that merchant ever."
    AggregationConfig customer_spend_agg(
        "customer_spend_all_time",
        {"customer_id", "merchant_id"},
        AggregationType::SUM,
        std::nullopt,  // all time
        "amount"
    );

    Aggregator aggregator(customer_spend_agg);
    for (const auto& record : sample_records) {
        aggregator.add_record(record.values, record.ts);
    }

    // Query without start/end - returns sum over all time
    auto test4 = aggregator.query_agg({{"customer_id", 1}, {"merchant_id", 1}});
    if (!test4 || *test4 != 100) {
        throw std::runtime_error("Expected 100, got " + optional_to_string(test4));
    }

    auto test5 = aggregator.query_agg({{"customer_id", 2}, {"merchant_id", 1}});
    if (!test5 || *test5 != 900) {
        throw std::runtime_error("Expected 900, got " + optional_to_string(test5));
    }

    auto test6 = aggregator.query_agg({{"customer_id", 1}, {"merchant_id", 2}});
    if (!test6 || *test6 != 200) {
        throw std::runtime_error("Expected 200, got " + optional_to_string(test6));
    }

    auto test7 = aggregator.query_agg({{"customer_id", 2}, {"merchant_id", 2}});
    if (!test7 || *test7 != 1200) {
        throw std::runtime_error("Expected 1200, got " + optional_to_string(test7));
    }

    auto test8 = aggregator.query_agg({{"customer_id", 3}, {"merchant_id", 1}});
    if (test8.has_value()) {
        throw std::runtime_error("Expected nullopt, got " + std::to_string(*test8));
    }
}

void test_part1_customer_average_spend_all_time() {
    // Mean aggregation with multiple group_by_columns fields, over all time
    // Example: "Given a customer-merchant pair, I want to know the average amount
    // they spent per transaction ever."
    AggregationConfig customer_average_spend_agg(
        "customer_average_spend",
        {"customer_id", "merchant_id"},
        AggregationType::MEAN,
        std::nullopt,  // all time
        "amount"
    );

    Aggregator aggregator(customer_average_spend_agg);
    for (const auto& record : sample_records) {
        aggregator.add_record(record.values, record.ts);
    }

    // Query without start/end - returns average over all time
    auto test18 = aggregator.query_agg({{"customer_id", 1}, {"merchant_id", 1}});
    if (!test18 || *test18 != 100) {
        throw std::runtime_error("Expected 100, got " + optional_to_string(test18));
    }

    auto test19 = aggregator.query_agg({{"customer_id", 1}, {"merchant_id", 2}});
    if (!test19 || *test19 != 200) {
        throw std::runtime_error("Expected 200, got " + optional_to_string(test19));
    }

    auto test20 = aggregator.query_agg({{"customer_id", 2}, {"merchant_id", 1}});
    if (!test20 || *test20 != 900) {
        throw std::runtime_error("Expected 900, got " + optional_to_string(test20));
    }

    auto test21 = aggregator.query_agg({{"customer_id", 2}, {"merchant_id", 2}});
    if (!test21 || *test21 != 600) {
        throw std::runtime_error("Expected 600, got " + optional_to_string(test21));
    }

    auto test22 = aggregator.query_agg({{"customer_id", 2}, {"merchant_id", 3}});
    if (test22.has_value()) {
        throw std::runtime_error("Expected nullopt, got " + std::to_string(*test22));
    }
}

void test_part2_revenue_with_time_bucketing() {
    // Sum aggregation with time bucketing, single group_by_columns field
    // Example: "Given a merchant id, I want to know their total revenue
    // in a specific time range."
    AggregationConfig revenue_agg(
        "revenue",
        {"merchant_id"},
        AggregationType::SUM,
        std::chrono::duration_cast<std::chrono::milliseconds>(days(2)),
        "amount"
    );

    Aggregator aggregator(revenue_agg);
    for (const auto& record : sample_records) {
        aggregator.add_record(record.values, record.ts);
    }

    // Query with time filtering - last 2 days
    auto test9 = aggregator.query_agg(
        {{"merchant_id", 1}},
        now - days(2),
        now
    );
    if (!test9 || *test9 != 1000) {
        throw std::runtime_error("Expected 1000, got " + optional_to_string(test9));
    }

    auto test10 = aggregator.query_agg(
        {{"merchant_id", 2}},
        now - days(2),
        now
    );
    if (test10.has_value() && *test10 != 0) {
        throw std::runtime_error("Expected nullopt or 0, got " + std::to_string(*test10));
    }

    // Query with time filtering - last 4 days
    auto test11 = aggregator.query_agg(
        {{"merchant_id", 2}},
        now - days(4),
        now
    );
    if (!test11 || *test11 != 700) {
        throw std::runtime_error("Expected 700, got " + optional_to_string(test11));
    }

    auto test12 = aggregator.query_agg(
        {{"merchant_id", 3}},
        now - std::chrono::hours(240),  // 10 days
        now
    );
    if (test12.has_value()) {
        throw std::runtime_error("Expected nullopt, got " + std::to_string(*test12));
    }
}

void test_part2_customer_spend_per_merchant_with_time_bucketing() {
    // Sum aggregation with time bucketing, multiple group_by_columns fields
    // Example: "Given a customer-merchant pair, I want to know the total amount
    // that customer spent at that merchant in a specific time range."
    AggregationConfig customer_spend_agg(
        "customer_spend_per_merchant",
        {"customer_id", "merchant_id"},
        AggregationType::SUM,
        std::chrono::duration_cast<std::chrono::milliseconds>(days(4)),
        "amount"
    );

    Aggregator aggregator(customer_spend_agg);
    for (const auto& record : sample_records) {
        aggregator.add_record(record.values, record.ts);
    }

    // Query with time filtering - last 4 days
    auto test13 = aggregator.query_agg(
        {{"customer_id", 1}, {"merchant_id", 1}},
        now - days(4),
        now
    );
    if (!test13 || *test13 != 100) {
        throw std::runtime_error("Expected 100, got " + optional_to_string(test13));
    }

    auto test14 = aggregator.query_agg(
        {{"customer_id", 2}, {"merchant_id", 1}},
        now - days(4),
        now
    );
    if (!test14 || *test14 != 900) {
        throw std::runtime_error("Expected 900, got " + optional_to_string(test14));
    }

    // Query with time filtering - last 12 days
    auto test15 = aggregator.query_agg(
        {{"customer_id", 1}, {"merchant_id", 2}},
        now - days(12),
        now
    );
    if (!test15 || *test15 != 200) {
        throw std::runtime_error("Expected 200, got " + optional_to_string(test15));
    }

    auto test16 = aggregator.query_agg(
        {{"customer_id", 2}, {"merchant_id", 2}},
        now - days(4),
        now
    );
    if (!test16 || *test16 != 500) {
        throw std::runtime_error("Expected 500, got " + optional_to_string(test16));
    }

    auto test17 = aggregator.query_agg(
        {{"customer_id", 3}, {"merchant_id", 1}},
        now - days(12),
        now
    );
    if (test17.has_value()) {
        throw std::runtime_error("Expected nullopt, got " + std::to_string(*test17));
    }
}

void test_part2_customer_average_spend_with_time_bucketing() {
    // Mean aggregation with time bucketing
    // Example: "Given a customer-merchant pair, I want to know the average amount
    // they spent per transaction in a specific time range."
    AggregationConfig customer_average_spend_agg(
        "customer_average_spend",
        {"customer_id", "merchant_id"},
        AggregationType::MEAN,
        std::chrono::duration_cast<std::chrono::milliseconds>(days(8)),
        "amount"
    );

    Aggregator aggregator(customer_average_spend_agg);
    for (const auto& record : sample_records) {
        aggregator.add_record(record.values, record.ts);
    }

    // Query with time filtering - last 16 days
    auto test18 = aggregator.query_agg(
        {{"customer_id", 1}, {"merchant_id", 1}},
        now - days(16),
        now
    );
    if (!test18 || *test18 != 100) {
        throw std::runtime_error("Expected 100, got " + optional_to_string(test18));
    }

    auto test19 = aggregator.query_agg(
        {{"customer_id", 1}, {"merchant_id", 2}},
        now - days(16),
        now
    );
    if (!test19 || *test19 != 200) {
        throw std::runtime_error("Expected 200, got " + optional_to_string(test19));
    }

    auto test20 = aggregator.query_agg(
        {{"customer_id", 2}, {"merchant_id", 1}},
        now - days(16),
        now
    );
    if (!test20 || *test20 != 900) {
        throw std::runtime_error("Expected 900, got " + optional_to_string(test20));
    }

    auto test21 = aggregator.query_agg(
        {{"customer_id", 2}, {"merchant_id", 2}},
        now - days(16),
        now
    );
    if (!test21 || *test21 != 600) {
        throw std::runtime_error("Expected 600, got " + optional_to_string(test21));
    }

    auto test22 = aggregator.query_agg(
        {{"customer_id", 2}, {"merchant_id", 3}},
        now - days(16),
        now
    );
    if (test22.has_value()) {
        throw std::runtime_error("Expected nullopt, got " + std::to_string(*test22));
    }
}

int main() {
    try {
        std::cout << "Running Part 1 tests..." << std::endl;
        test_part1_example();
        test_part1_order_count_all_time();
        test_part1_customer_spend_per_merchant_all_time();
        test_part1_customer_average_spend_all_time();
        std::cout << "Part 1 tests passed!" << std::endl;

        std::cout << "\nRunning Part 2 tests..." << std::endl;
        test_part2_example();
        test_part2_revenue_with_time_bucketing();
        test_part2_customer_spend_per_merchant_with_time_bucketing();
        test_part2_customer_average_spend_with_time_bucketing();
        std::cout << "Part 2 tests passed!" << std::endl;

        std::cout << "\nAll tests passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

import java.time.Duration;
import java.time.Instant;
import java.util.List;
import java.util.Map;
import java.util.Optional;

/*
 * EXAMPLE DOMAIN: Merchants and Customers
 *
 * We live in a world with merchants and customers, where customers make orders
 * to these merchants. Each record the aggregator receives comes with the following fields:
 *
 *   - merchant_id: int
 *   - customer_id: int
 *   - amount:      float
 */

public class Tests {

    record Record(Map<String, Integer> values, Instant ts) {}

    // Fixes current time so that the tests are deterministic and query start and
    // end times fall on bucket boundaries if buckets are constructed such that their
    // boundaries align with the Unix epoch.
    static final Instant now = Instant.parse("2026-04-01T00:00:00Z");

    // Sample records to be added to aggregators
    static final List<Record> sampleRecords = List.of(
        new Record(Map.of("merchant_id", 1, "customer_id", 1, "amount", 100), now.minus(Duration.ofDays(1))), // 1 day ago
        new Record(Map.of("merchant_id", 1, "customer_id", 2, "amount", 900), now.minus(Duration.ofHours(6))),// 6 hours ago
        new Record(Map.of("merchant_id", 2, "customer_id", 1, "amount", 200), now.minus(Duration.ofDays(3))), // 3 days ago
        new Record(Map.of("merchant_id", 2, "customer_id", 2, "amount", 500), now.minus(Duration.ofDays(3))), // 3 days ago
        new Record(Map.of("merchant_id", 2, "customer_id", 2, "amount", 700), now.minus(Duration.ofDays(7))) // 7 days ago
    );

    // -------------------------------------------------------------------------
    // Assertion helpers
    // -------------------------------------------------------------------------

    static void assertEqual(Optional<Double> actual, double expected, String msg) {
        if (actual.isEmpty() || actual.get() != expected) {
            throw new AssertionError(msg + " — expected " + expected + ", got " + actual.map(Object::toString).orElse("empty"));
        }
    }

    static void assertEmpty(Optional<Double> actual, String msg) {
        if (actual.isPresent()) {
            throw new AssertionError(msg + " — expected empty, got " + actual.get());
        }
    }

    static void assertEmptyOrZero(Optional<Double> actual, String msg) {
        if (actual.isPresent() && actual.get() != 0) {
            throw new AssertionError(msg + " — expected empty or 0, got " + actual.get());
        }
    }

    /*
     * PART 1: Aggregations Over All Time
     *
     * This part focuses on aggregations over all time.
     * You should aggregate all records ever seen, regardless of their timestamp.
     * Supports single and multiple groupByColumns fields.
     *
     * Examples:
     *   - "Given a merchant id, I want to know their total number of orders ever."
     *   - "Given a customer-merchant pair, I want to know the total amount
     *     that customer spent at that merchant ever."
     *   - "Given a customer-merchant pair, I want to know the average amount
     *     they spent per transaction ever."
     */

    static void testPart1Example() {
        AggregationConfig config = new AggregationConfig(
            "merchant_sales",
            List.of("merchant_id"),
            AggregationType.MEAN,
            null,
            "amount"
        );

        Aggregator aggregator = new Aggregator(config);

        aggregator.addRecord(Map.of("merchant_id", 1, "customer_id", 1, "amount", 100), now.minus(Duration.ofDays(1)));
        aggregator.addRecord(Map.of("merchant_id", 1, "customer_id", 2, "amount", 200), now.minus(Duration.ofDays(3)));
        aggregator.addRecord(Map.of("merchant_id", 2, "customer_id", 1, "amount", 300), now.minus(Duration.ofDays(7)));
        aggregator.addRecord(Map.of("merchant_id", 2, "customer_id", 2, "amount", 400), now.minus(Duration.ofDays(2)));
        aggregator.addRecord(Map.of("merchant_id", 2, "customer_id", 2, "amount", 500), now.minus(Duration.ofDays(5)));

        // note that ts doesn't matter in this part
        assertEqual(aggregator.queryAgg(Map.of("merchant_id", 1)), 150, "part1Example-1");
        assertEqual(aggregator.queryAgg(Map.of("merchant_id", 2)), 400, "part1Example-2");
    }

    static void testPart1OrderCountAllTime() {
        // Count aggregation with single groupByColumns field, over all time
        // Example: "Given a merchant id, I want to know their total number of orders ever."
        AggregationConfig orderCountAgg = new AggregationConfig(
            "order_count_all_time",
            List.of("merchant_id"),
            AggregationType.COUNT,
            null,   // all time
            null    // Count doesn't need a field
        );

        Aggregator aggregator = new Aggregator(orderCountAgg);
        for (Record r : sampleRecords) {
            aggregator.addRecord(r.values(), r.ts());
        }

        // Query without start/end - returns count over all time
        var test1 = aggregator.queryAgg(Map.of("merchant_id", 1));
        assertEqual(test1, 2, "test1");  // 2 orders total

        var test2 = aggregator.queryAgg(Map.of("merchant_id", 2));
        assertEqual(test2, 3, "test2");  // 3 orders total

        var test3 = aggregator.queryAgg(Map.of("merchant_id", 3));
        assertEmpty(test3, "test3");     // No such merchant
    }

    static void testPart1CustomerSpendPerMerchantAllTime() {
        // Sum aggregation with multiple groupByColumns fields, over all time
        // Example: "Given a customer-merchant pair, I want to know the total amount
        // that customer spent at that merchant ever."
        AggregationConfig customerSpendAgg = new AggregationConfig(
            "customer_spend_all_time",
            List.of("customer_id", "merchant_id"),
            AggregationType.SUM,
            null,      // all time
            "amount"
        );

        Aggregator aggregator = new Aggregator(customerSpendAgg);
        for (Record r : sampleRecords) {
            aggregator.addRecord(r.values(), r.ts());
        }

        // Query without start/end - returns sum over all time
        var test4 = aggregator.queryAgg(Map.of("customer_id", 1, "merchant_id", 1));
        assertEqual(test4, 100, "test4");   // 100

        var test5 = aggregator.queryAgg(Map.of("customer_id", 2, "merchant_id", 1));
        assertEqual(test5, 900, "test5");   // 900

        var test6 = aggregator.queryAgg(Map.of("customer_id", 1, "merchant_id", 2));
        assertEqual(test6, 200, "test6");   // 200

        var test7 = aggregator.queryAgg(Map.of("customer_id", 2, "merchant_id", 2));
        assertEqual(test7, 1200, "test7");  // 500 + 700

        var test8 = aggregator.queryAgg(Map.of("customer_id", 3, "merchant_id", 1));
        assertEmpty(test8, "test8");        // No such customer-merchant pair
    }

    static void testPart1CustomerAverageSpendAllTime() {
        // Mean aggregation with multiple groupByColumns fields, over all time
        // Example: "Given a customer-merchant pair, I want to know the average amount
        // they spent per transaction ever."
        AggregationConfig customerAverageSpendAgg = new AggregationConfig(
            "customer_average_spend",
            List.of("customer_id", "merchant_id"),
            AggregationType.MEAN,
            null,      // all time
            "amount"
        );

        Aggregator aggregator = new Aggregator(customerAverageSpendAgg);
        for (Record r : sampleRecords) {
            aggregator.addRecord(r.values(), r.ts());
        }

        // Query without start/end - returns average over all time
        var test18 = aggregator.queryAgg(Map.of("customer_id", 1, "merchant_id", 1));
        assertEqual(test18, 100, "test18");  // Average of [100] = 100

        var test19 = aggregator.queryAgg(Map.of("customer_id", 1, "merchant_id", 2));
        assertEqual(test19, 200, "test19");  // Average of [200] = 200

        var test20 = aggregator.queryAgg(Map.of("customer_id", 2, "merchant_id", 1));
        assertEqual(test20, 900, "test20");  // Average of [900] = 900

        var test21 = aggregator.queryAgg(Map.of("customer_id", 2, "merchant_id", 2));
        assertEqual(test21, 600, "test21");  // Average of [500, 700] = 600

        var test22 = aggregator.queryAgg(Map.of("customer_id", 2, "merchant_id", 3));
        assertEmpty(test22, "test22");       // No such customer-merchant pair
    }

    /*
     * PART 2: Aggregations with Time Bucketing
     *
     * This part adds time bucketing to aggregations. Records are grouped into
     * time buckets based on bucketDuration, and queries filter by time range.
     *
     * Examples:
     *   - "Given a merchant id, what is their total revenue in the last 1 day?"
     *   - "Given a customer-merchant pair, what is their total spend in the last 10 days?"
     *   - "Given a customer-merchant pair, I want to know the average amount
     *     they spent per transaction in the last 10 days."
     */

    static void testPart2Example() {
        AggregationConfig config = new AggregationConfig(
            "merchant_sales_with_time",
            List.of("merchant_id"),
            AggregationType.MEAN,
            Duration.ofDays(2),
            "amount"
        );

        Aggregator aggregator = new Aggregator(config);

        aggregator.addRecord(Map.of("merchant_id", 1, "customer_id", 1, "amount", 100), now.minus(Duration.ofDays(1)));
        aggregator.addRecord(Map.of("merchant_id", 1, "customer_id", 2, "amount", 200), now.minus(Duration.ofDays(3)));
        aggregator.addRecord(Map.of("merchant_id", 2, "customer_id", 1, "amount", 300), now.minus(Duration.ofHours(12)));
        aggregator.addRecord(Map.of("merchant_id", 2, "customer_id", 2, "amount", 400), now.minus(Duration.ofDays(5)));
        aggregator.addRecord(Map.of("merchant_id", 2, "customer_id", 2, "amount", 500), now.minus(Duration.ofDays(7)));

        assertEqual(aggregator.queryAgg(Map.of("merchant_id", 1), now.minus(Duration.ofDays(2)), now),
            100, "part2Example-1"); // only 100 falls between

        assertEqual(aggregator.queryAgg(Map.of("merchant_id", 1), now.minus(Duration.ofDays(14)), now),
            150, "part2Example-2"); // both 100 and 200 fall between

        assertEqual(aggregator.queryAgg(Map.of("merchant_id", 2), now.minus(Duration.ofDays(6)), now),
            350, "part2Example-3"); // both 300 and 400 fall between

        assertEqual(aggregator.queryAgg(Map.of("merchant_id", 2), now.minus(Duration.ofDays(6)), now.minus(Duration.ofDays(4))),
            400, "part2Example-4"); // only 400 falls between
    }

    static void testPart2RevenueWithTimeBucketing() {
        // Sum aggregation with time bucketing, single groupByColumns field
        // Example: "Given a merchant id, I want to know their total revenue
        // in a specific time range."
        AggregationConfig revenueAgg = new AggregationConfig(
            "revenue",
            List.of("merchant_id"),
            AggregationType.SUM,
            Duration.ofDays(2),  // 2-day buckets
            "amount"
        );

        Aggregator aggregator = new Aggregator(revenueAgg);
        for (Record r : sampleRecords) {
            aggregator.addRecord(r.values(), r.ts());
        }

        // Query with time filtering - last 2 days
        var test9 = aggregator.queryAgg(
            Map.of("merchant_id", 1),
            now.minus(Duration.ofDays(2)),
            now
        );
        assertEqual(test9, 1000, "test9");   // 100 + 900 (both within last 2 days day)

        var test10 = aggregator.queryAgg(
            Map.of("merchant_id", 2),
            now.minus(Duration.ofDays(2)),
            now
        );
        assertEmptyOrZero(test10, "test10"); // No revenue in the last 2 days

        // Query with time filtering - last 4 days
        var test11 = aggregator.queryAgg(
            Map.of("merchant_id", 2),
            now.minus(Duration.ofDays(4)),
            now
        );
        assertEqual(test11, 700, "test11");  // 200 + 500

        var test12 = aggregator.queryAgg(
            Map.of("merchant_id", 3),
            now.minus(Duration.ofDays(10)),
            now
        );
        assertEmpty(test12, "test12");       // No such merchant
    }

    static void testPart2CustomerSpendPerMerchantWithTimeBucketing() {
        // Sum aggregation with multiple groupByColumns fields, with time bucketing
        // Example: "Given a customer-merchant pair, I want to know the total amount
        // that customer spent at that merchant in a specific time range."
        AggregationConfig customerSpendAgg = new AggregationConfig(
            "customer_spend_per_merchant",
            List.of("customer_id", "merchant_id"),
            AggregationType.SUM,
            Duration.ofDays(4),  // 4-day buckets
            "amount"
        );

        Aggregator aggregator = new Aggregator(customerSpendAgg);
        for (Record r : sampleRecords) {
            aggregator.addRecord(r.values(), r.ts());
        }

        // Query with time filtering - last 4 days
        var test13 = aggregator.queryAgg(
            Map.of("customer_id", 1, "merchant_id", 1),
            now.minus(Duration.ofDays(4)),
            now
        );
        assertEqual(test13, 100, "test13");  // 100 in the last 4 days

        var test14 = aggregator.queryAgg(
            Map.of("customer_id", 2, "merchant_id", 1),
            now.minus(Duration.ofDays(4)),
            now
        );
        assertEqual(test14, 900, "test14");  // 900 in the last 4 days

        // Query with time filtering - last 12 days
        var test15 = aggregator.queryAgg(
            Map.of("customer_id", 1, "merchant_id", 2),
            now.minus(Duration.ofDays(12)),
            now
        );
        assertEqual(test15, 200, "test15");  // 200 in the last 12 days

        var test16 = aggregator.queryAgg(
            Map.of("customer_id", 2, "merchant_id", 2),
            now.minus(Duration.ofDays(4)),
            now
        );
        assertEqual(test16, 500, "test16");  // 500 in the last 4 days

        var test17 = aggregator.queryAgg(
            Map.of("customer_id", 3, "merchant_id", 1),
            now.minus(Duration.ofDays(12)),
            now
        );
        assertEmpty(test17, "test17");       // No such customer-merchant pair
    }

    static void testPart2CustomerAverageSpendWithTimeBucketing() {
        // Mean aggregation with time bucketing
        // Example: "Given a customer-merchant pair, I want to know the average amount
        // they spent per transaction in a specific time range."
        AggregationConfig customerAverageSpendAgg = new AggregationConfig(
            "customer_average_spend",
            List.of("customer_id", "merchant_id"),
            AggregationType.MEAN,
            Duration.ofDays(8),  // 8-day buckets
            "amount"
        );

        Aggregator aggregator = new Aggregator(customerAverageSpendAgg);
        for (Record r : sampleRecords) {
            aggregator.addRecord(r.values(), r.ts());
        }

        // Query with time filtering - last 16 days
        var test18 = aggregator.queryAgg(
            Map.of("customer_id", 1, "merchant_id", 1),
            now.minus(Duration.ofDays(16)),
            now
        );
        assertEqual(test18, 100, "test18");  // Average of [100] = 100

        var test19 = aggregator.queryAgg(
            Map.of("customer_id", 1, "merchant_id", 2),
            now.minus(Duration.ofDays(16)),
            now
        );
        assertEqual(test19, 200, "test19");  // Average of [200] = 200

        var test20 = aggregator.queryAgg(
            Map.of("customer_id", 2, "merchant_id", 1),
            now.minus(Duration.ofDays(16)),
            now
        );
        assertEqual(test20, 900, "test20");  // Average of [900] = 900

        var test21 = aggregator.queryAgg(
            Map.of("customer_id", 2, "merchant_id", 2),
            now.minus(Duration.ofDays(16)),
            now
        );
        assertEqual(test21, 600, "test21");  // Average of [500, 700] = 600

        var test22 = aggregator.queryAgg(
            Map.of("customer_id", 2, "merchant_id", 3),
            now.minus(Duration.ofDays(16)),
            now
        );
        assertEmpty(test22, "test22");       // No such customer-merchant pair
    }

    public static void main(String[] args) {
        try {
            System.out.println("Running Part 1 tests...");
            testPart1Example();
            testPart1OrderCountAllTime();
            testPart1CustomerSpendPerMerchantAllTime();
            testPart1CustomerAverageSpendAllTime();
            System.out.println("Part 1 tests passed!");

            System.out.println("\nRunning Part 2 tests...");
            testPart2Example();
            testPart2RevenueWithTimeBucketing();
            testPart2CustomerSpendPerMerchantWithTimeBucketing();
            testPart2CustomerAverageSpendWithTimeBucketing();
            System.out.println("Part 2 tests passed!");

            System.out.println("\nAll tests passed!");
        } catch (AssertionError e) {
            System.err.println("Test failed: " + e.getMessage());
            System.exit(1);
        }
    }
}

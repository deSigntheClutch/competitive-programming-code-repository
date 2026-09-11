#include <chrono>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

/*
AGGREGATION SYSTEM

In this problem, you'll build an aggregation system optimized for fast queries.
The system receives a stream of events, each with a timestamp and various
fields. Your task is to compute and store aggregate features like sums and
averages, grouped by specified fields.

To see example usage and expected outputs, see `test_part1_example` and
`test_part2_example` in main.cpp
*/

enum class AggregationType {
    SUM,
    COUNT,
    MEAN
};

struct AggregationConfig {
    //! Unique identifier for the aggregate feature.
    std::string name;
  
    //! What fields to group by. When querying this aggregate, these values will be the input fields.
    std::vector<std::string> group_by_columns;

    //! What aggregation to compute.
    AggregationType aggregation;

    //! The time window for the aggregation. Buckets
    //! - Use nullopt for no time bucketing (aggregate over all time)
    //! - Use a duration for time bucketing (e.g., std::chrono::hours(1), std::chrono::hours(24))
    std::optional<std::chrono::milliseconds> bucket_duration;

    //! The field to aggregate over. That is, the field whose values will be summed, averaged, etc.
    //! If the aggregation is COUNT, this will be nullopt.
    std::optional<std::string> value_column;

    AggregationConfig(const std::string& name,
                      const std::vector<std::string>& group_by_columns,
                      AggregationType aggregation,
                      const std::optional<std::chrono::milliseconds>& bucket_duration,
                      const std::optional<std::string>& value_column = std::nullopt) :
        name(name), group_by_columns(group_by_columns), aggregation(aggregation),
        bucket_duration(bucket_duration), value_column(value_column) {}
};

/*
Implement the Aggregator class below.
Look at the tests in main.cpp for further instructions on how to use the Aggregator class.
*/

class Aggregator {
public:
    AggregationConfig config_;
    std::unordered_map<std::string, int> sumValue;
    std::unordered_map<std::string, int> sumCnt;

    explicit Aggregator(const AggregationConfig& config) : config_(config) {}

    // Build a deterministic key by walking group_by_columns IN CONFIG ORDER,
    // so add_record and query_agg always agree even though the input map is unordered.
    std::string make_key(const std::unordered_map<std::string, int>& fields) {
        std::string key;
        for (const auto& col : config_.group_by_columns) {
            auto it = fields.find(col);
            if (it == fields.end()) {
                return "";  // missing a required grouping column
            }
            key += col + "=" + std::to_string(it->second) + ";";
        }
        return key;
    }

    void add_record(const std::unordered_map<std::string, int>& row,
                    const std::chrono::system_clock::time_point& ts) {
        const std::string key = make_key(row);

        // For COUNT, value_column is nullopt, so the value doesn't matter.
        int value = 0;
        if (config_.value_column.has_value()) {
            auto it = row.find(*config_.value_column);
            if (it != row.end()) {
                value = it->second;
            }
        }

        sumValue[key] += value;  // running sum
        sumCnt[key] += 1;        // running count
    }

    std::optional<double> query_agg(
        const std::unordered_map<std::string, int>& group,
        const std::optional<std::chrono::system_clock::time_point>& start = std::nullopt,
        const std::optional<std::chrono::system_clock::time_point>& end = std::nullopt
    ) {
        const std::string key = make_key(group);

        auto it = sumCnt.find(key);
        if (it == sumCnt.end()) {
            return std::nullopt;  // group never seen
        }
        const int count = it->second;
        const int total = sumValue[key];

        switch (config_.aggregation) {
            case AggregationType::SUM:
                return static_cast<double>(total);
            case AggregationType::COUNT:
                return static_cast<double>(count);
            case AggregationType::MEAN:
                return static_cast<double>(total) / count;
        }
        return std::nullopt;
    }
    std::unordered_map<std::string, int> parse_key(std::string_view key) {
      std::unordered_map<std::string, int> result;
      size_t start = 0;
      while (start < key.size()) {
          size_t semi = key.find(';', start);
          if (semi == std::string_view::npos) semi = key.size();
          auto seg = key.substr(start, semi - start);   // "customer_id=2"
          start = semi + 1;

          auto eq = seg.find('=');
          auto name = seg.substr(0, eq);
          auto num  = seg.substr(eq + 1);
          int val;
          std::from_chars(num.data(), num.data() + num.size(), val);
          result.emplace(name, val);
      }
      return result;
    }
};

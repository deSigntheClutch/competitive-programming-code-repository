import java.time.Duration;
import java.time.Instant;
import java.util.List;
import java.util.Map;
import java.util.Optional;

/*
 * AGGREGATION SYSTEM
 *
 * In this problem, you'll build an aggregation system optimized for fast queries.
 * The system receives a stream of events, each with a timestamp and various
 * fields. Your task is to compute and store aggregate features like sums and
 * averages, grouped by specified fields.
 *
 * To see example usage and expected outputs, see testPart1Example and
 * testPart2Example in Tests.java.
 */

enum AggregationType {
    SUM, COUNT, MEAN
}

class AggregationConfig {
    /** Unique identifier for the aggregate feature. */
    public final String name;

    /** What fields to group by. When querying this aggregate, these values will be the input fields. */
    public final List<String> groupByColumns;

    /** What aggregation to compute */
    public final AggregationType aggregation;

    /**
     * The time window for the aggregation. Buckets
     * - Use null for no time bucketing (aggregate over all time)
     * - Use a Duration for time bucketing (e.g., Duration.ofHours(1), Duration.ofDays(1))
     */
    public final Duration bucketDuration;

    /**
     * The field to aggregate over. That is, the field whose values will be summed, averaged, etc.
     * If the aggregation is COUNT, this will be null.
     */
    public final String valueColumn;

    public AggregationConfig(String name, List<String> groupByColumns, AggregationType aggregation,
                             Duration bucketDuration, String valueColumn) {
        this.name = name;
        this.groupByColumns = groupByColumns;
        this.aggregation = aggregation;
        this.bucketDuration = bucketDuration;
        this.valueColumn = valueColumn;
    }
}

/**
 * Implement the Aggregator class below.
 * Look at the tests in Tests.java for further instructions on how to use the Aggregator class.
 */
class Aggregator {

    public Aggregator(AggregationConfig config) {
        // TODO: Initialize your aggregator
    }

    /**
     * Add a new record to the aggregator.
     */
    public void addRecord(Map<String, Integer> row, Instant ts) {
        // TODO: Add a new record to the aggregator
    }

    /**
     * Query the aggregate for a certain group.
     */
    public Optional<Double> queryAgg(Map<String, Integer> group) {
        return queryAgg(group, null, null);
    }

    /**
     * Query the aggregate for a certain group.
     *
     * If start/end are null, query over all time (Part 1).
     * If start/end are non-null, query within that time range (Part 2+).
     *
     * Returns Optional.empty() if the group does not exist.
     * The group's keys will be exactly those in groupByColumns.
     */
    public Optional<Double> queryAgg(Map<String, Integer> group, Instant start, Instant end) {
        // TODO: Query the aggregate for a certain group.
        // If start/end are null, query over all time (Part 1).
        // If start/end are non-null, query within that time range (Part 2+).
        // Should return Optional.empty() if the group does not exist.
        // The group's keys will be exactly those in groupByColumns.
        return Optional.empty();
    }
}

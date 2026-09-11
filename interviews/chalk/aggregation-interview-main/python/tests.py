from datetime import datetime, timedelta, timezone

from aggregates import AggregationConfig, Aggregator

"""
EXAMPLE DOMAIN: Merchants and Customers

We live in a world with merchants and customers, where customers make orders
to these merchants. Each record the aggregator receives comes with the following fields:

- merchant_id: int
- customer_id: int
- amount: float

"""

# Fixes current time so that the tests are deterministic and query start and
# end times fall on bucket boundaries if buckets are constructed such that their boundaries
# align with the Unix epoch.
now = datetime(2026, 4, 1, 0, 0, tzinfo=timezone.utc)


################################################################################
# PART 1: Aggregations Over All Time
################################################################################
"""
PART 1: Aggregations Over All Time

This part focuses on aggregations over all time.
You should aggregate all records ever seen, regardless of their timestamp.
Supports single and multiple group_by_columns fields.

Examples:
- "Given a merchant id, I want to know their total number of orders ever."
- "Given a customer-merchant pair, I want to know the total amount
  that customer spent at that merchant ever."
- "Given a customer-merchant pair, I want to know the average amount
  they spent per transaction ever."
"""


def test_part1_example():
    config = AggregationConfig(
        name="merchant_sales",
        group_by_columns=["merchant_id"],
        aggregation="mean",
        bucket_duration="all",
        value_column="amount",
    )

    aggregator = Aggregator(config)

    aggregator.add_record(row={"merchant_id": 1, "customer_id": 1, "amount": 100}, ts=now - timedelta(days=1))
    aggregator.add_record(row={"merchant_id": 1, "customer_id": 2, "amount": 200}, ts=now - timedelta(days=3))
    aggregator.add_record(row={"merchant_id": 2, "customer_id": 1, "amount": 300}, ts=now - timedelta(days=7))
    aggregator.add_record(row={"merchant_id": 2, "customer_id": 2, "amount": 400}, ts=now - timedelta(days=2))
    aggregator.add_record(row={"merchant_id": 2, "customer_id": 2, "amount": 500}, ts=now - timedelta(days=5))

    # note that ts doesn't matter in this part
    assert aggregator.query_agg(group={"merchant_id": 1}) == 150  # (100+200)/2 = 150
    assert aggregator.query_agg(group={"merchant_id": 2}) == 400  # (300+400+500)/3 = 400


# Sample records to be added to aggregators
sample_records = [
    {
        "values": {"merchant_id": 1, "customer_id": 1, "amount": 100},
        "ts": now - timedelta(days=1),  # 1 day ago
    },
    {
        "values": {"merchant_id": 1, "customer_id": 2, "amount": 900},
        "ts": now - timedelta(hours=6),  # 6 hours ago
    },
    {
        "values": {"merchant_id": 2, "customer_id": 1, "amount": 200},
        "ts": now - timedelta(days=3),  # 3 days ago
    },
    {
        "values": {"merchant_id": 2, "customer_id": 2, "amount": 500},
        "ts": now - timedelta(days=3),  # 3 days ago
    },
    {
        "values": {"merchant_id": 2, "customer_id": 2, "amount": 700},
        "ts": now - timedelta(days=7),  # 7 days ago
    },
]


def test_part1_order_count_all_time():
    # Count aggregation with single group_by_columns field, over all time
    # Example: "Given a merchant id, I want to know their total number of orders ever."
    order_count_agg = AggregationConfig(
        name="order_count_all_time",
        group_by_columns=["merchant_id"],
        aggregation="count",
        bucket_duration="all",
        value_column=None,  # Count doesn't need a field
    )

    aggregator = Aggregator(config=order_count_agg)
    for record in sample_records:
        aggregator.add_record(row=record["values"], ts=record["ts"])

    # Query without start/end - returns count over all time
    test1 = aggregator.query_agg(group={"merchant_id": 1})
    assert test1 == 2, f"Expected {2}, got {test1}"  # 2 orders total

    test2 = aggregator.query_agg(group={"merchant_id": 2})
    assert test2 == 3, f"Expected {3}, got {test2}"  # 3 orders total

    test3 = aggregator.query_agg(group={"merchant_id": 3})
    assert test3 is None, f"Expected None, got {test3}"  # No such merchant


def test_part1_customer_spend_per_merchant_all_time():
    # Sum aggregation with multiple group_by_columns fields, over all time
    # Example: "Given a customer-merchant pair, I want to know the total amount
    # that customer spent at that merchant ever."
    customer_spend_agg = AggregationConfig(
        name="customer_spend_all_time",
        group_by_columns=["customer_id", "merchant_id"],
        aggregation="sum",
        bucket_duration="all",
        value_column="amount",
    )

    aggregator = Aggregator(config=customer_spend_agg)
    for record in sample_records:
        aggregator.add_record(row=record["values"], ts=record["ts"])

    # Query without start/end - returns sum over all time
    test4 = aggregator.query_agg(group={"customer_id": 1, "merchant_id": 1})
    assert test4 == 100, f"Expected {100}, got {test4}"  # 100

    test5 = aggregator.query_agg(group={"customer_id": 2, "merchant_id": 1})
    assert test5 == 900, f"Expected {900}, got {test5}"  # 900

    test6 = aggregator.query_agg(group={"customer_id": 1, "merchant_id": 2})
    assert test6 == 200, f"Expected {200}, got {test6}"  # 200

    test7 = aggregator.query_agg(group={"customer_id": 2, "merchant_id": 2})
    assert test7 == 1200, f"Expected {1200}, got {test7}"  # 500 + 700

    test8 = aggregator.query_agg(group={"customer_id": 3, "merchant_id": 1})
    assert test8 is None, f"Expected None, got {test8}"  # No such customer-merchant pair


def test_part1_customer_average_spend_all_time():
    # Mean aggregation with multiple group_by_columns fields, over all time
    # Example: "Given a customer-merchant pair, I want to know the average amount
    # they spent per transaction ever."
    customer_average_spend_agg = AggregationConfig(
        name="customer_average_spend",
        group_by_columns=["customer_id", "merchant_id"],
        aggregation="mean",
        bucket_duration="all",
        value_column="amount",
    )

    aggregator = Aggregator(config=customer_average_spend_agg)
    for record in sample_records:
        aggregator.add_record(row=record["values"], ts=record["ts"])

    # Query without start/end - returns average over all time
    test18 = aggregator.query_agg(group={"customer_id": 1, "merchant_id": 1})
    assert test18 == 100, f"Expected {100}, got {test18}"  # Average of [100] = 100

    test19 = aggregator.query_agg(group={"customer_id": 1, "merchant_id": 2})
    assert test19 == 200, f"Expected {200}, got {test19}"  # Average of [200] = 200

    test20 = aggregator.query_agg(group={"customer_id": 2, "merchant_id": 1})
    assert test20 == 900, f"Expected {900}, got {test20}"  # Average of [900] = 900

    test21 = aggregator.query_agg(group={"customer_id": 2, "merchant_id": 2})
    assert test21 == 600, f"Expected {600}, got {test21}"  # Average of [500, 700] = 600

    test22 = aggregator.query_agg(group={"customer_id": 2, "merchant_id": 3})
    assert test22 is None, f"Expected None, got {test22}"  # No such customer-merchant pair


################################################################################
# PART 2: Aggregations with Time Bucketing
################################################################################
"""
PART 2: Aggregations with Time Bucketing

This part adds time bucketing to aggregations. Records are grouped into
time buckets based on bucket_duration, and queries filter by time range.

Examples:
- "Given a merchant id, what is their total revenue in the last 1 day?"
- "Given a customer-merchant pair, what is their total spend in the last 10 days?"
- "Given a customer-merchant pair, I want to know the average amount
  they spent per transaction in the last 10 days."
"""


def test_part2_example():
    config = AggregationConfig(
        name="merchant_sales_with_time",
        group_by_columns=["merchant_id"],
        aggregation="mean",
        bucket_duration=timedelta(days=2),
        value_column="amount",
    )

    aggregator = Aggregator(config)

    aggregator.add_record(row={"merchant_id": 1, "customer_id": 1, "amount": 100}, ts=now - timedelta(days=1))

    aggregator.add_record(row={"merchant_id": 1, "customer_id": 2, "amount": 200}, ts=now - timedelta(days=3))

    aggregator.add_record(row={"merchant_id": 2, "customer_id": 1, "amount": 300}, ts=now - timedelta(hours=12))

    aggregator.add_record(row={"merchant_id": 2, "customer_id": 2, "amount": 400}, ts=now - timedelta(days=5))

    aggregator.add_record(row={"merchant_id": 2, "customer_id": 2, "amount": 500}, ts=now - timedelta(days=7))

    assert (
        aggregator.query_agg(group={"merchant_id": 1}, start=now - timedelta(days=2), end=now) == 100
    )  # only 100 falls between

    assert (
        aggregator.query_agg(group={"merchant_id": 1}, start=now - timedelta(days=14), end=now) == 150
    )  # both 100 and 200 fall between

    assert (
        aggregator.query_agg(
            group={"merchant_id": 2},
            start=now - timedelta(days=6),
            end=now,
        )
        == 350
    )  # both 300 and 400 fall between

    assert (
        aggregator.query_agg(
            group={"merchant_id": 2},
            start=now - timedelta(days=6),
            end=now - timedelta(days=4),
        )
        == 400
    )  # only 400 fall between


def test_part2_revenue_with_time_bucketing():
    # Sum aggregation with time bucketing, single group_by_columns field
    # Example: "Given a merchant id, I want to know their total revenue
    # in a specific time range."
    revenue_agg = AggregationConfig(
        name="revenue",
        group_by_columns=["merchant_id"],
        aggregation="sum",
        bucket_duration=timedelta(days=2),
        value_column="amount",
    )

    aggregator = Aggregator(config=revenue_agg)
    for record in sample_records:
        aggregator.add_record(row=record["values"], ts=record["ts"])

    # Query with time filtering - last 2 days
    test9 = aggregator.query_agg(
        group={"merchant_id": 1},
        start=now - timedelta(days=2),
        end=now,
    )
    assert test9 == 1000, f"Expected {1000}, got {test9}"  # 100 + 900 (both within last 2 days day)

    test10 = aggregator.query_agg(
        group={"merchant_id": 2},
        start=now - timedelta(days=2),
        end=now,
    )
    assert test10 in (None, 0), f"Expected None or 0, got {test10}"  # No revenue in the last 2 days

    # Query with time filtering - last 4 days
    test11 = aggregator.query_agg(
        group={"merchant_id": 2},
        start=now - timedelta(days=4),
        end=now,
    )
    assert test11 == 700, f"Expected {700}, got {test11}"  # 200 + 500

    test12 = aggregator.query_agg(
        group={"merchant_id": 3},
        start=now - timedelta(days=10),
        end=now,
    )
    assert test12 is None, f"Expected None, got {test12}"  # No such merchant


def test_part2_customer_spend_per_merchant_with_time_bucketing():
    # Sum aggregation with time bucketing, multiple group_by_columns fields
    # Example: "Given a customer-merchant pair, I want to know the total amount
    # that customer spent at that merchant in a specific time range."
    customer_spend_agg = AggregationConfig(
        name="customer_spend_per_merchant",
        group_by_columns=["customer_id", "merchant_id"],
        aggregation="sum",
        bucket_duration=timedelta(days=4),
        value_column="amount",
    )

    aggregator = Aggregator(config=customer_spend_agg)
    for record in sample_records:
        aggregator.add_record(row=record["values"], ts=record["ts"])

    # Query with time filtering - last 4 days
    test13 = aggregator.query_agg(
        group={"customer_id": 1, "merchant_id": 1},
        start=now - timedelta(days=4),
        end=now,
    )
    assert test13 == 100, f"Expected {100}, got {test13}"  # 100 in the last 4 days

    test14 = aggregator.query_agg(
        group={"customer_id": 2, "merchant_id": 1},
        start=now - timedelta(days=4),
        end=now,
    )
    assert test14 == 900, f"Expected {900}, got {test14}"  # 900 in the last 4 days

    # Query with time filtering - last 12 days
    test15 = aggregator.query_agg(
        group={"customer_id": 1, "merchant_id": 2},
        start=now - timedelta(days=12),
        end=now,
    )
    assert test15 == 200, f"Expected {200}, got {test15}"  # 200 in the last 12 days

    test16 = aggregator.query_agg(
        group={"customer_id": 2, "merchant_id": 2},
        start=now - timedelta(days=4),
        end=now,
    )
    assert test16 == 500, f"Expected {500}, got {test16}"  # 500 in the last 4 days

    test17 = aggregator.query_agg(
        group={"customer_id": 3, "merchant_id": 1},
        start=now - timedelta(days=12),
        end=now,
    )
    assert test17 is None, f"Expected None, got {test17}"  # No such customer-merchant pair


def test_part2_customer_average_spend_with_time_bucketing():
    # Mean aggregation with time bucketing
    # Example: "Given a customer-merchant pair, I want to know the average amount
    # they spent per transaction in a specific time range."
    customer_average_spend_agg = AggregationConfig(
        name="customer_average_spend",
        group_by_columns=["customer_id", "merchant_id"],
        aggregation="mean",
        bucket_duration=timedelta(days=8),
        value_column="amount",
    )

    aggregator = Aggregator(config=customer_average_spend_agg)
    for record in sample_records:
        aggregator.add_record(row=record["values"], ts=record["ts"])

    # Query with time filtering - last 16 days
    test18 = aggregator.query_agg(
        group={"customer_id": 1, "merchant_id": 1},
        start=now - timedelta(days=16),
        end=now,
    )
    assert test18 == 100, f"Expected {100}, got {test18}"  # Average of [100] = 100

    test19 = aggregator.query_agg(
        group={"customer_id": 1, "merchant_id": 2},
        start=now - timedelta(days=16),
        end=now,
    )
    assert test19 == 200, f"Expected {200}, got {test19}"  # Average of [200] = 200

    test20 = aggregator.query_agg(
        group={"customer_id": 2, "merchant_id": 1},
        start=now - timedelta(days=16),
        end=now,
    )
    assert test20 == 900, f"Expected {900}, got {test20}"  # Average of [900] = 900

    test21 = aggregator.query_agg(
        group={"customer_id": 2, "merchant_id": 2},
        start=now - timedelta(days=16),
        end=now,
    )
    assert test21 == 600, f"Expected {600}, got {test21}"  # Average of [500, 700] = 600

    test22 = aggregator.query_agg(
        group={"customer_id": 2, "merchant_id": 3},
        start=now - timedelta(days=16),
        end=now,
    )
    assert test22 is None, f"Expected None, got {test22}"  # No such customer-merchant pair


################################################################################
# Run all tests
################################################################################

if __name__ == "__main__":
    print("Running Part 1 tests...")
    test_part1_example()
    test_part1_order_count_all_time()
    test_part1_customer_spend_per_merchant_all_time()
    test_part1_customer_average_spend_all_time()
    print("Part 1 tests passed!")

    print("\nRunning Part 2 tests...")
    test_part2_example()
    test_part2_revenue_with_time_bucketing()
    test_part2_customer_spend_per_merchant_with_time_bucketing()
    test_part2_customer_average_spend_with_time_bucketing()
    print("Part 2 tests passed!")

    print("\nAll tests passed!")

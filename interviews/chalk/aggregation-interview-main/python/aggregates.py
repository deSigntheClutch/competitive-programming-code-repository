from collections import defaultdict
from dataclasses import dataclass
from datetime import datetime, timedelta
from typing import Literal


"""

AGGREGATION SYSTEM

In this problem, you'll build an aggregation system optimized for fast queries.
The system receives a stream of events, each with a timestamp and various
fields. Your task is to compute and store aggregate features like sums and
averages, grouped by specified fields.

To see example usage and expected outputs, see `test_part1_example` and
`test_part2_example` in tests.py

"""


@dataclass
class AggregationConfig:
    """Unique identifier for the aggregate feature."""

    name: str

    group_by_columns: list[str]
    """What fields to group by. When querying this aggregate, these values will be the input fields."""

    aggregation: Literal["sum", "count", "mean"]
    """What aggregation to compute"""

    bucket_duration: Literal["all"] | timedelta
    """
    The time window for the aggregation. Buckets 
    - Use "all" for no time bucketing (aggregate over all time)
    - Use a timedelta for time bucketing (e.g., timedelta(hours=1), timedelta(days=1))
    """

    value_column: str | None
    """
    The field to aggregate over. That is, the field whose values will be summed, averaged, etc.
    If the aggregation is "count", this will be None.
    """


"""
Implement the Aggregator class below.
Look at the tests in tests.py for further instructions on how to use the Aggregator class.
"""


class Aggregator:
    aggConfig: AggregationConfig

    counter = defaultdict(int)

    merchBucket = defaultdict(list) # merchId, [customerId, value, time]
    customerBucket = defaultdict(list) # customerId, [merchId, value, time]
    def __init__(self, config: AggregationConfig):
        """
        The aggregation this instance should maintain.
        """
        self.aggConfig = config

        # key 2^n per group_by_columns
        self.counter = defaultdict(int)
        self.sum = defaultdict(int)



    def add_record(self, row: dict[str, float | int], ts: datetime) -> None:
        """
        Add a new record to the aggregator.
        """
        key = defaultdict(int)
        for item in self.aggConfig.group_by_columns:
            print(item)
            if item in row.keys():
                key[item] = int(row[item])

        if self.aggConfig.value_column:
            self.sum[str(key)] += row[self.aggConfig.value_column]
            self.counter[str(key)] += 1
        else:
            self.sum[str(key)] += 1
            self.counter[str(key)] = 1

    def query_agg(
        self,
        group: dict[str, float | int],
        start: datetime | None = None,
        end: datetime | None = None,
    ) -> float | None:
        """
        Query the aggregate for a certain group.

        If start/end are None, query over all time (Part 1).
        If start/end are provided, query within that time range (Part 2+).

        Should return None if the group does not exist.
        The group's keys will be exactly those in group_by_columns.
        """
        # Part 1 start & end = None
        key = defaultdict(int)
        for item in self.aggConfig.group_by_columns:
            key[item] = int(group[item])
        print(str(key), self.counter[str(key)], self.sum[str(key)])

        if self.aggConfig.aggregation == "sum":
            return None if self.counter[str(key)] == 0 else self.sum[str(key)]
        elif self.aggConfig.aggregation == "count":
            return None if self.counter[str(key)] == 0 else self.sum[str(key)]
        elif self.aggConfig.aggregation == "mean":
            return None if self.counter[str(key)] == 0 else self.sum[str(key)]/self.counter[str(key)]


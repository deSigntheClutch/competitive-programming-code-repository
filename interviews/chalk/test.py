# ------------- PROBLEM STATEMENT ------------- #

# You are a data scientist working on flood mitigation in a mountainous province.
# Streams flow down from the mountains onto a high desert plain, where they combine
# and eventually merge into one large river. At some junctions, there is a
# water gauge that measures the flow rate in cubic feet per second (cfs).
#
# In the desert plain, there are a number of small towns along the rivers that
# want to predict how much water will flow through their riverbeds after a storm.
#
# Your task is to implement the following interface:
# 1: `update(flow_datum)` - called whenever a gauge logs a new reading
# 2: `expected_runoff(town, timestamp)` - computes the total expected flow `town`
#    expects to see at `timestamp`, given the gauge readings and the average time
#    it takes the water to flow through each river segment
#
# As input, you will receive a RiverNode tree that encodes the structure of the system
# and how long it takes water to flow through segments of river.
#
# Clarifications/Assumptions:
# 1: if `update` is called with a river_id `r` and timestamp `ts`, all future calls to `update`
#    with river_id `r` will have timestamp `ts_prime > ts`
# 2: assume that the total flow of water is conserved through the system - ie no water gets lost
#    or added to the system after it passes through a gauge (no net evaporation/rainfall/seepage)
# 3: you can assume that there will be many more calls to `update` than to `expected_runoff` when
#    reasoning about runtime tradeoffs between the two methods

# ------------- IMPLEMENTATION ------------- #

from dataclasses import dataclass
from datetime import datetime, timedelta
from collections import defaultdict

RiverId = int

@dataclass
class RiverNode:
    river_id: RiverId
    town_name: str | None
    has_gauge: bool
    float_time: timedelta # how long it takes water (on average) to flow to its downstream parent
    upstream_nodes: list["RiverNode"]

@dataclass
class FlowDatum:
    river_id: RiverId
    ts: datetime
    flow: int

class MountainRunoff:
    G = defaultdict(list)
    riverMap = dict()
    nameMap = dict()
    contribution = defaultdict(list) # river_id, list of 'event'
    flow_datum_list = []

    def construct(self, cur):
        self.riverMap[cur.river_id] = cur
        self.nameMap[cur.town_name] = cur.river_id # TODO: can be None
        for node in cur.upstream_nodes:
            self.G[node.river_id].append((cur.river_id, node.float_time.total_seconds()))
            self.construct(node)

    def dfs(self, river_id, timestamp: int, value: int) -> FlowDatum:
        self.contribution[river_id].append((river_id, timestamp, value))

        for child, weight in self.G[river_id]:
            self.dfs(child, timestamp + weight, value)

    def __init__(self, river_system: RiverNode):
        self.construct(river_system)
        print(self.G)

    def update(self, flow_datum: FlowDatum):
        self.dfs(flow_datum.river_id, flow_datum.ts.timestamp(), flow_datum.flow)
        print(self.contribution[13])
        pass

    # convert
    def expected_runoff(self, town: str, timestamp: datetime) -> int | None:
        if town not in self.nameMap:
            return None

        r_id = self.nameMap[town]
        findFlag = False
        answer = 0
        for ts, value in self.contribution[r_id]:
            if ts <= timestamp.timestamp(): # <-
                findFlag = True
                answer += value
        # print(town, timestamp, "-->", answer)
        if not findFlag:
            return None

        return answer


# ------------- SAMPLE DATA ------------- #

flow_data = [
    FlowDatum(5,  datetime(year=2026, month=2, day=1, hour=5),  5000),
    FlowDatum(6,  datetime(year=2026, month=2, day=1, hour=5),  4000),
    FlowDatum(7,  datetime(year=2026, month=2, day=1, hour=6),  3000),
    FlowDatum(11, datetime(year=2026, month=2, day=1, hour=6),  5000),
    FlowDatum(14, datetime(year=2026, month=2, day=1, hour=6),  6000),
    FlowDatum(15, datetime(year=2026, month=2, day=1, hour=7),  2000),
    FlowDatum(5,  datetime(year=2026, month=2, day=2, hour=5),  4000),
    FlowDatum(6,  datetime(year=2026, month=2, day=2, hour=7),  3000),
    FlowDatum(7,  datetime(year=2026, month=2, day=2, hour=11), 1000),
    FlowDatum(14, datetime(year=2026, month=2, day=2, hour=12), 3000),
    FlowDatum(15, datetime(year=2026, month=2, day=2, hour=12), 3000),
    FlowDatum(11, datetime(year=2026, month=2, day=2, hour=14), 500),
    FlowDatum(5,  datetime(year=2026, month=2, day=3, hour=2),  7000),
    FlowDatum(7,  datetime(year=2026, month=2, day=3, hour=5),  6000),
    FlowDatum(11, datetime(year=2026, month=2, day=3, hour=7),  4000),
    FlowDatum(6,  datetime(year=2026, month=2, day=3, hour=6),  8000),
    FlowDatum(14, datetime(year=2026, month=2, day=3, hour=8),  9000),
    FlowDatum(15, datetime(year=2026, month=2, day=3, hour=10), 3000),
    FlowDatum(5,  datetime(year=2026, month=2, day=4, hour=5),  2000),
    FlowDatum(6,  datetime(year=2026, month=2, day=4, hour=5),  500),
    FlowDatum(7,  datetime(year=2026, month=2, day=4, hour=6),  1000),
    FlowDatum(11, datetime(year=2026, month=2, day=4, hour=8),  1500),
    FlowDatum(14, datetime(year=2026, month=2, day=4, hour=6),  2000),
    FlowDatum(15, datetime(year=2026, month=2, day=4, hour=7),  1000),
]

# ------------- RIVER SYSTEM ------------- #

river_system = RiverNode(river_id=0, town_name=None, has_gauge=False, float_time=timedelta(0), upstream_nodes=[
    RiverNode(river_id=1, town_name="abilene", has_gauge=False, float_time=timedelta(hours=5), upstream_nodes=[
        RiverNode(river_id=2, town_name=None, has_gauge=False, float_time=timedelta(hours=5), upstream_nodes=[
            RiverNode(river_id=3, town_name="bigfoot", has_gauge=False, float_time=timedelta(hours=2), upstream_nodes=[
                RiverNode(river_id=4, town_name=None, has_gauge=False, float_time=timedelta(hours=4), upstream_nodes=[
                    RiverNode(river_id=5,  town_name=None, has_gauge=True, float_time=timedelta(hours=5), upstream_nodes=[]),
                    RiverNode(river_id=6,  town_name=None, has_gauge=True, float_time=timedelta(hours=6), upstream_nodes=[]),
                    RiverNode(river_id=7,  town_name=None, has_gauge=True, float_time=timedelta(hours=5), upstream_nodes=[]),
                ]),
            ]),
            RiverNode(river_id=8, town_name="cadbury", has_gauge=False, float_time=timedelta(hours=1), upstream_nodes=[
                RiverNode(river_id=9, town_name="davenport", has_gauge=False, float_time=timedelta(hours=3), upstream_nodes=[
                    RiverNode(river_id=10, town_name=None, has_gauge=False, float_time=timedelta(hours=2), upstream_nodes=[
                        RiverNode(river_id=11, town_name=None, has_gauge=True, float_time=timedelta(hours=5), upstream_nodes=[]),
                        RiverNode(river_id=12, town_name="eagle", has_gauge=False, float_time=timedelta(hours=1), upstream_nodes=[
                            RiverNode(river_id=13, town_name=None, has_gauge=False, float_time=timedelta(hours=2), upstream_nodes=[
                                RiverNode(river_id=14, town_name=None, has_gauge=True, float_time=timedelta(hours=2), upstream_nodes=[]),
                                RiverNode(river_id=15, town_name=None, has_gauge=True, float_time=timedelta(hours=2), upstream_nodes=[]),
                            ]),
                        ]),
                    ]),
                ]),
            ]),
        ]),
    ]),
])

# ------------- EXAMPLE ------------- #

# assert mountain_runoff.expected_runoff("eagle", datetime(year=2026, month=2, day=4, hour=10, minute=30)) == 5000
#
# The town of Eagle is downstream of gauges on rivers 14 and 15. It takes 4 hours from water to flow from the gauges to
# Eagle. Since Eagle wants to know its flow at day 4, hour 10.5, we need to look at the gauges' flows as of day 4, hour 6.5
#
# Gauge 14's latest entry is at day 4, hour 6, reading 2000 cfs. Gauge 15's latest entry is at day 3, hour 10 (note we cannot
# use the day 4 reading from gauge 15 because it is in the future of the time we want to sample), reading 3000 cfs. Therefore,
# the town of Eagle estimates it'll see a flow of 5000 cfs on 2/4/26 at 10:30 am

# ------------- BASIC TESTS ------------- #

# Here, we test your implementation when there is only one data point per gauge:
# Gauge 5  -> 5000
# Gauge 6  -> 4000
# Gauge 7  -> 3000
# Gauge 11 -> 5000
# Gauge 14 -> 6000
# Gauge 15 -> 2000

mountain_runoff = MountainRunoff(river_system)
for flow_datum in flow_data[:6]:
    mountain_runoff.update(flow_datum)

assert mountain_runoff.expected_runoff("eagle",    datetime(year=2026, month=2, day=4, hour=10, minute=30)) == 8000  # 14 + 15
assert mountain_runoff.expected_runoff("cadbury",  datetime(year=2026, month=2, day=4, hour=9,  minute=30)) == 13000 # 11 + 14 + 15
assert mountain_runoff.expected_runoff("bigfoot",  datetime(year=2026, month=2, day=4, hour=19, minute=30)) == 12000 # 5 + 6 + 7
assert mountain_runoff.expected_runoff("abilene",  datetime(year=2026, month=2, day=4, hour=21, minute=30)) == 25000 # all

# ------------- FULL TESTS ------------- #

mountain_runoff = MountainRunoff(river_system)

for flow_datum in flow_data:
    mountain_runoff.update(flow_datum)

assert mountain_runoff.expected_runoff("ficticious", datetime(year=2026, month=2, day=4, hour=6,  minute=30)) is None
assert mountain_runoff.expected_runoff("eagle",      datetime(year=2026, month=2, day=4, hour=10, minute=30)) == 5000
assert mountain_runoff.expected_runoff("davenport",  datetime(year=2026, month=2, day=1, hour=13, minute=30)) is None
assert mountain_runoff.expected_runoff("cadbury",    datetime(year=2026, month=2, day=2, hour=9,  minute=30)) == 13000
assert mountain_runoff.expected_runoff("bigfoot",    datetime(year=2026, month=2, day=2, hour=19, minute=30)) == 10000
assert mountain_runoff.expected_runoff("abilene",    datetime(year=2026, month=2, day=3, hour=21, minute=30)) == 22500
assert mountain_runoff.expected_runoff("abilene",    datetime(year=2026, month=2, day=3, hour=20, minute=30)) == 17500

for i in range(10):
    # Davenport is 3 hours upstream of Cadbury, so we expect their expected flows to match at any time when offset by 3 hrs
    assert (
        mountain_runoff.expected_runoff("cadbury",  datetime(year=2026, month=2, day=1, hour=10, minute=30) + (i * timedelta(hours=8)))
        == mountain_runoff.expected_runoff("davenport", datetime(year=2026, month=2, day=1, hour=10, minute=30) + (i * timedelta(hours=8)) - timedelta(hours=3))
    )
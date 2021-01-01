n, m = map(int, raw_input().split())
s = str(raw_input())
t = str(raw_input())
length = len(s)
ans = len(s) + 1
set = []

def cmp(s1, s2):
    x = len(s1)
    res = 0
    pos = []
    for i in range(0, x):
        if s1[i] != s2[i]:
            res += 1
            pos.append(i + 1)
    return res, pos

for i, x in enumerate(t):
    if(i + length > len(t)): break
    v = t[i:(i + length)]
    cur, curSet = cmp(s, v)
    if(cur < ans):
        ans, set = cur, curSet

print ans

for x in set:
    print x,

"""

4 10
abcd
ebceabazcd

"""
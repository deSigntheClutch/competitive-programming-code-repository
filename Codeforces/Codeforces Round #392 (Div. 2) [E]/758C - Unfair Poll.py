n, m, k, x, y=map(int, raw_input().split())
t = [0 for i in range(n)]
len = 0
for i in range(n): t[i] += 1; len += 1
for i in range(n - 2,0,-1): t[i] += 1; len += 1
len *= m
md = k % len
ti = k / len
c = [[0 for i in range(m)] for j in range(n)]
for i in range(n):
    for j in range(m):
        c[i][j] = t[i] * ti
while md > 0:
    for i in range(n):
        for j in range(m):
            if(md == 0): break
            else: c[i][j] += 1; md -= 1;
    for i in range(n - 2,0,-1):
        for j in range(m):
            if (md == 0): break
            else: c[i][j] += 1; md -= 1;
print max([max(c[i]) for i in range(n)]), min([min(c[i]) for i in range(n)]), c[x - 1][y - 1];
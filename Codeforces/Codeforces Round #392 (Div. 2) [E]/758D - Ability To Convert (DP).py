inf = 10L ** 20
n = long(input())
str = raw_input()
l = len(str)
f = [inf] * (l + 1)
f[0] = 0L
for i in range(l):
    cur = 0
    if(str[i] == '0'): f[i + 1] = min(f[i + 1], f[i] * n); continue
    for j in range(i, l):
        cur = cur * 10L + long(str[j])
        if(cur >= n): break
        f[j + 1] = min(f[j + 1], f[i] * n + cur)
print f[l]

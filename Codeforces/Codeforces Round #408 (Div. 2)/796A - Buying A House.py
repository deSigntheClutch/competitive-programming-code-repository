a = []
ans = int(1e9 + 10)

n, m, k = map(int,raw_input().split())
m -= 1
a = map(int, raw_input().split())

for i in range(0, n):
  if(a[i] == 0 or a[i] > k): continue
  ans = min(ans, abs(m - i))
  
print ans * 10

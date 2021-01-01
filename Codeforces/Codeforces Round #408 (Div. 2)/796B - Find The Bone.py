n, m, k = map(int, raw_input().split())
tmp = set(map(int, raw_input().split()))

ans = 0; vis = 0
if ans + 1 in tmp: vis = 1

for cs in range(k):
    a, b = map(int, raw_input().split())
    a -= 1; b -= 1
    if(vis == 1): continue
    if(a == ans): ans = b
    elif(b == ans): ans = a
    if ans + 1 in tmp: vis = 1

print ans + 1

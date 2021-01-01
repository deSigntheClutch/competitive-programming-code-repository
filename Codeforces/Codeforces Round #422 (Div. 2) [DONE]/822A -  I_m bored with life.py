A, B = map(int, raw_input().split())
if A > B: A, B = B, A
ans = 1
for x in range(1, A + 1):
    ans = ans * x
print ans
# math.factorial()
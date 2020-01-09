from decimal import *

getcontext().prec = 100

s = 36

a = [0 for i in range(s + 1)]
b = [0 for i in range(s + 1)]

def dfs(now, tot, n, m, c):
    if now > n:
        c[tot] += 1
        return
    for i in range(1, m + 1):
        dfs(now + 1, tot + i, n, m, c)

dfs(1, 0, 9, 4, a)
dfs(1, 0, 6, 6, b)

ans0, ans1 = Decimal(0), sum(a) * sum(b)

for i in range(1, s + 1):
    ans0 += a[i] * b[i - 1]
    b[i] += b[i - 1]

print(ans0 / ans1)
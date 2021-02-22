dp = [[[0 for i in range(8)] for i in range(16)] for i in range(16)]

def calc(x):
    if x == 0:  return 1
    if x == 1:  return 2
    if x == 10: return 4
    return 0

for i in range(16):
    dp[0][i][calc(i)] = 1

for i in range(1, 16):
    for j in range(16):
        for k in range(16):
            for t in range(8):
                dp[i][j][t | calc(j)] += dp[i - 1][k][t]

ans = 0
for i in range(2, 16):
    for j in range(1, 16):
        ans += dp[i][j][7]

x, y = 'abcdef', 'ABCDEF'
t, ans = hex(ans)[2:], ''
for i in t:
    if i in x:
        ans += y[x.index(i)]
    else:
        ans += i

print(ans)
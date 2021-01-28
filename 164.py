dp = [[[0 for i in range(10)] for i in range(10)] for i in range(30)]

for i in range(1, 10):
    for j in range(10 - i):
        dp[2][i][j] = 1

for k in range(3, 21):
    for i in range(0, 10):
        for j in range(10 - i):
            for d in range(10 - i - j):
                dp[k][j][d] += dp[k - 1][i][j]

ans = 0
for i in range(0, 10):
    for j in range(10 - i):
        ans += dp[20][i][j]

print(ans)

# 378158756814587
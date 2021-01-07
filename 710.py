n, m = 100000000, 10 ** 6 
# even_len, even_len_with_2, ans
dp = [[0, 0, 0] for i in range(n)]
dp[0] = [1, 0, 0]
dp[1] = [0, 0, 0]
dp[2] = [1, 0, 1]
dp[3] = [0, 0, 0]
dp[4] = [2, 1, 2]

ss = [[0, 0] for i in range(n)]
ss[0][0] = 1

def md(x):
    for i in range(len(x)):
        while x[i] >= m:
            x[i] -= m
        while x[i] < 0:
            x[i] += m

for i in range(2, 5):
    ss[i][0] = dp[i][0] + ss[i - 2][0]
    ss[i][1] = dp[i][1] + ss[i - 2][1]

for i in range(5, n):
    dp[i][0] += ss[i - 2][0]
    dp[i][1] += ss[i - 2][1]
    '''
    for j in range(1, i // 2 + 1):
        dp[i][0] += dp[i - j - j][0]
        dp[i][1] += dp[i - j - j][1]
    '''
    dp[i][1] += dp[i - 4][0] - dp[i - 4][1]
    
    st = 1
    if i % 2 == 0: st = 2
    '''
    for j in range(st, i + 1, 2):
       dp[i][2] += dp[i - j][1]
    '''
    dp[i][2] += ss[i - st][1]
    dp[i][2] += dp[i][1] + dp[i - 2][0] - dp[i - 2][1]
    md(dp[i])
    if dp[i][2] == 0: 
        print(i)
        break
    ss[i][0] = dp[i][0] + ss[i - 2][0]
    ss[i][1] = dp[i][1] + ss[i - 2][1]
    md(ss[i])
    #print(i, dp[i], ss[i])

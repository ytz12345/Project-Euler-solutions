from eulerlib import get_prime, memoize

N = 50000
p, v = get_prime(N)

@memoize
def is_prime(x):
    x = int(x)
    if x < N:
        return v[x] == 0
    for i in range(1, p[0] + 1):
        if x % p[i] == 0:
            return 0
        if p[i] * p[i] > x:
            break
    return 1

def dfs(pre, siz, sumlimit):
    n = len(pre)
    if n == siz:return True
    start = 1 if n == 0 else pre[-1] + 1
    for i in range(start, p[0] + 1):
        if p[i] * (siz - n) >= sumlimit:
            break
        if all(is_prime(str(p[x]) + str(p[i])) and is_prime(str(p[i]) + str(p[x])) for x in pre):
            pre.append(i)
            if dfs(pre, siz, sumlimit - p[i]):
                return True
            pre.pop()
    return False

sumlimit = N
ans, tmp = [], []
while True:
    tmp = []
    if dfs(tmp, 5, sumlimit):
        ans = [p[x] for x in tmp]
        sumlimit = sum(ans) - 1
    else:
        print(ans)
        break
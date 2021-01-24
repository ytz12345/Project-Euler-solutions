from eulerlib import get_prime
from math import gcd
from time import time

n = 501
p, v = get_prime(n)
v[1] = 1
ans = [[0, 1] for i in range(n)]

def add(x, y):
    g = gcd(x[1], y[1])
    return [x[0] * y[1] // g + y[0] * x[1] // g, x[1] * y[1] // g]

s = 'PPPPNNPPPNPPNPN'

def jump(i, now, pos, sm):
    global s, ans, v

    if pos == len(s):
        ans[i] = add(ans[i], sm)
        return

    if ((v[now] == 0) ^ (s[pos] == 'N')) == 1:
        sm = [sm[0] * 2, sm[1] * 3]
    else:
        sm = [sm[0], sm[1] * 3]

    if now == 1:
        jump(i, now + 1, pos + 1, sm)
    elif now == n - 1:
        jump(i, now - 1, pos + 1, sm)
    else:
        jump(i, now - 1, pos + 1, [sm[0], sm[1] * 2])
        jump(i, now + 1, pos + 1, [sm[0], sm[1] * 2])

st = time()
res = [0, 1]
for i in range(1, n):
    jump(i, i, 0, [1, 1])
    res = add(res, ans[i])
res[1] *= 500
g = gcd(res[0], res[1])
res[0] //= g
res[1] //= g
print(str(res[0]) + '/' + str(res[1]))

print(time() - st)
# 199740353/29386561536000
# 33.02440690994263
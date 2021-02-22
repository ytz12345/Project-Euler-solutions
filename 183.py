from math import log, gcd

def c(x, y): return y * log(x / y)

def calc(x):
    l, r, k = 1, x, 5
    while l + k < r:
        m1, m2 = (l + l + r) // 3, (l + r + r) // 3
        a1, a2 = c(x, m1), c(x, m2)
        if a1 < a2: 
            l = m1
        else:
            r = m2
    
    y, z = r, c(x, r)
    for i in range(l, r):
        t = c(x, i)
        if t > z:
            y, z = i, t

    return y

ans = 0
for i in range(5, 10000 + 1):
    j = calc(i)
    j = j // gcd(i, j)
    while j % 2 == 0: j = j // 2
    while j % 5 == 0: j = j // 5
    if j == 1: 
        ans -= i
    else:
        ans += i

print(ans)
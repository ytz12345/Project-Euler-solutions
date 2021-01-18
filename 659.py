from math import gcd
def sqr(x): return x*x

for j in range(1, 50):
    k = j * j
    ans = 0
    p = 0
    for i in range(2, 100000):
        t= gcd(sqr(i)+k,sqr(i-1)+k)
        if t > ans:
            ans = t
            p = i
    print(j, ans, p)
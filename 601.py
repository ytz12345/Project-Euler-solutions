from math import gcd

def P(k, n_max):
    if k == 1:
        return n_max // 2 - 1

    x = 1
    for i in range(2, k + 1):
        x = x * i // gcd(x, i)
    y = x * (k + 1) // gcd(x, k + 1)
    if x == y: return 0 

    k = (n_max // y)
    r = (y // x - 1) * k

    remain = (n_max - 1) - k * y
    # print(x, y, r, remain)
    if remain <= 0: return r

    s = (remain - 1) // x + 1
    return r + (s - 1)

# print(P(3, 14))
# 1
# print(P(6, 10 ** 6))
# 14286

print(sum(P(i, 4 ** i) for i in range(1, 32)))
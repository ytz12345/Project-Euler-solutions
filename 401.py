n, m, ans = 10 ** 15, 10 ** 9, 0

def c(x): return (x * (x + 1) * (x * 2 + 1) // 6) % m
def cc(l, r): return c(r) - c(l - 1)

now, last = 1, 0
while now <= n:
    k = n // now
    last = n // k
    ans = (ans + cc(now, last) * k % m) % m
    now = last + 1

print((ans % m + m) % m)
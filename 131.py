from eulerlib import is_prime

def cub(x): return x ** 3

lim = 10 ** 6
ans = 0

for i in range(1, 600):
    for j in range(1, i)[::-1]:
        k = cub(i) - cub(j)
        if k > lim: break
        if is_prime(k): ans += 1

print(ans)
# 173
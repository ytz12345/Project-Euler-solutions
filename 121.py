n = 15
p, q, t = 0, 1, 1
for i in range(n): q *= i + 2
for i in range(1 << n):
    c = sum(((i >> j) & 1) for j in range(n))
    if c >= (n + 1) // 2: continue
    for j in range(n):
        if (i >> j) & 1:
            t *= j + 1
    p += t
    t = 1
print(p, q, q // p)

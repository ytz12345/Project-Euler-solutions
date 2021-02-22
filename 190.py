def calc(x):
    a = [2.0 * (i + 1) / (x + 1) for i in range(x)]
    s = 1
    for i in range(x): s *= a[i] ** (i + 1)
    s = int(s)
    print(x, s)
    return s

print(sum(calc(x) for x in range(2, 16)))
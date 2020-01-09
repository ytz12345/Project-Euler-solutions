from eulerlib import is_pandigital, get_fib, get_fib_front_k
from math import sqrt

s = set()
n = 10 ** 6
f = get_fib(n, 10 ** 9)

for i in range(1, n + 1):
    if is_pandigital(f[i]):
        s.add(i)

for i in range(1, n + 1):
    if is_pandigital(get_fib_front_k(i, 9)) and i in s:
        print(i)
        break
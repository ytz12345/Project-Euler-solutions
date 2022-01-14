'''
for r in range(-2, 2 + 1):
    print(r, len(str(s(5000)))) 
'''
'''
-2 1509
-1 4
0 3
1 9
2 1511
'''

'''
r = -1 -> s(5000) = 7500
r = 0 -> s(5000) = 897
r = 1 -> s(5000) = -33007500
r = 1.005 -> s(5000) = -1.826722368026899e+17
'''

from time import time
st = time()

eps = 1e-18
l, r, mid = 1, 1.005, 0
def u(k):
    return (900 - k * 3) * pow(mid, k - 1)
def s(n):
    return sum(u(k) for k in range(1, n + 1))

for i in range(100):
    mid = (l + r) * 0.5
    if s(5000) > -600000000000:
        l = mid + eps
    else:
        r = mid - eps

print(mid)
print(time() - st)

# 1.002322108633
# 0.1502377986907959
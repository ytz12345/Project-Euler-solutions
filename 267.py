def calc(x):
    l, r = 0, 1000
    ans = -1
    while l <= r:
        mid = (l + r) // 2
        if pow(1 - x, mid) * pow(1 + x * 2, 1000 - mid) >= 1e9:
            ans = mid
            l = mid + 1
        else: 
            r = mid - 1
    return ans


l, r = 0, 1
for i in range(100):
    la = calc((l + l + r) / 3.0)
    ra = calc((l + r + r) / 3.0)
    if la > ra: 
        r = (l + r + r) / 3.0
    else: 
        l = (l + l + r) / 3.0
#print(l, r, calc(l), calc(r))

ans = 1
k = calc(l)
f, l, r = 1, 1, 1000
for i in range(1, k + 1):
    f = f * r // l
    ans += f
    l += 1
    r -= 1
print(ans / pow(2, 1000))
#0.999992836187
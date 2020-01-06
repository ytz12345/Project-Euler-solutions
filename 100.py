'''
use bruteforce to print first 10 valid number of blue balls
you will find the pattern
'''
def get_red_from_blue(a):
    l, r = 0, a
    while l <= r:
        mid = (l + r) // 2
        if a * (a - 1) * 2 == (a + mid) * (a + mid - 1):
            return mid
        if a * (a - 1) * 2 < (a + mid) * (a + mid - 1):
            r = mid - 1
        else:
            l = mid + 1
    return -1

a = [3, 15]
lim = 10 ** 12

while True:
    a.append(a[-1] * 6 - (a[-2] + 2))
    assert get_red_from_blue(a[-1]) != -1
    if a[-1] + get_red_from_blue(a[-1]) > lim:
        for i in a:
            print(i)
        break
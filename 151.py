from math import gcd

s = []

def sim(c):
    g = gcd(c[0], c[1])
    return [c[0] // g, c[1] // g]

def add(a, b):
    return sim([a[0] * b[1] + a[1] * b[0], a[1] * b[1]])

cache = {}

def dfs(a):
    sa = str(a)
    if sa in cache:
        return cache[sa]

    #print(a)
    res = [0, 1]
    if len(a) == 1:
        if a[0] == 1: 
            res = [0, 1]
        else:
            b = [a[0] // 2]
            while b[-1] != 1:
                b.append(b[-1] // 2)
            res = add([1, 1], dfs(b))
    else:
        for i in range(len(a)):
            b = a[:i] + a[i+1:]
            if a[i] != 1:
                b.append(a[i] // 2)
                while b[-1] != 1:
                    b.append(b[-1] // 2)
            res = add(res, dfs(b))
        res = sim([res[0], res[1] * len(a)])

    cache[sa] = res
    return res

ans = dfs([8, 4, 2, 1])
print(ans[0]/ans[1])
# 0.46439878160108705
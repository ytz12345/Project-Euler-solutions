def c(n, m): 
    x = 1
    for i in range(1, m + 1):
        x *= n + 1 - i
        x //= i
    return x

def calc(n):
    r = 0
    for i in range(1, n):
        r += c(n, i) - 1
    return r

n = 26
ans = 0
for i in range(2, n+1):
    ans = max(ans, calc(i) * c(n, i))
print(ans)
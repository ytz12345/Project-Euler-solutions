dp = [[] for i in range(11)]
dp[1] = [[1]]
for i in range(2, 10):
    for j in range(1, i + 1):
        for k in dp[i - j]:
            if k[-1] <= j:
                tmp = [x for x in k]
                tmp.append(j)
                dp[i].append(tmp)
    dp[i].append([i])

PRINT = False
if PRINT:
    for i in range(1, 10):
        print(i)
        for j in dp[i]:
            print(j)

n = 2020
m = 10 ** 16
num_n_1 = int('1' * n) % m
ans = 0

mem_map = {}
def c(n, m):
    if (n, m) in mem_map:
        return mem_map[(n, m)]
    ret = 1
    for i in range(0, m):
        ret *= n - i
        ret //= i + 1
    mem_map[(n, m)] = ret
    return ret

for i in range(1, 10):
    for j in dp[i]:
        st = {}
        for k in range(1, 10):
            st[k] = 0
        for k in j:
            st[k] += 1
        st[i] += 1
        for k in range(1, 10):
            if k not in st or st[k] == 0:
                continue
            st[k] -= 1

            sm = n - 1
            temp = k
            for num in st:
                if st[num] != 0:
                    temp = temp * c(sm, st[num]) % m
                    sm -= st[num]
            ans = ans + temp % m

            st[k] += 1

ans = ans * num_n_1 % m
print(ans)
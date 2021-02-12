from eulerlib import is_prime

ans, n = 0, 10

for i in range(1, 10):
    s = [str(i)] * n
    ok = False
    for j in range(n):
        for k in range(0, 10):
            s[j] = str(k)
            if s[0] == '0': continue
            x = int(''.join(s))
            if is_prime(x):
                ans += x
                ok = True
                # print(x)
            s[j] = str(i)
    
    # if ok == False:
    #    print(i)
    # 2
    # 8

for i in [0, 2, 8]:
    s = [str(i)] * n
    ok = False
    for j in range(n):
        for k in range(j + 1, n):
            for x in range(0, 10):
                s[j] = str(x)
                for y in range(0, 10):
                    s[k] = str(y)
                    if s[0] == '0': continue
                    x = int(''.join(s))
                    if is_prime(x):
                        ans += x
                        ok = True
                        print(x)
                    s[k] = str(i)
                s[j] = str(i)
    
    if ok == False:
        print(i)

print(ans)
# 612407567715

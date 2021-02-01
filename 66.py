from eulerlib import get_fraction_by_sqrt, is_sqr, sqr

ans, x = 0, 0

for i in range(1, 1000 + 1):
    if not is_sqr(i):
        res = get_fraction_by_sqrt(i)
        for p, q in res:
            if sqr(p) - sqr(q) * i == 1:
                #print(p, q, i)
                if p > x:
                    x = p
                    ans = i
                break

print(ans, x)
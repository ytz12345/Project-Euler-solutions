from eulerlib import get_fraction_by_sqrt

ans, cnt = 0, 0
for p, q in get_fraction_by_sqrt(5):
    if p * p - q * q * 5 == -1:
        ans += q
        cnt += 1
        if cnt >= 12:
            break

print(ans)
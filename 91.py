from eulerlib import point

n = 50
ans = 0
for x1 in range(n + 1):
    for y1 in range(n + 1):
        for x2 in range(n + 1):
            for y2 in range(n + 1):
                if x1 == 0 and y1 == 0:continue
                if x2 == 0 and y2 == 0:continue
                if x1 == x2 and y1 == y2:continue
                x, y, z = point(x1, y1), point(x2, y2), point(0, 0)
                if x * y == 0 or (x - y) * y == 0 or (y - x) * x == 0:
                    ans += 1

print(ans // 2)
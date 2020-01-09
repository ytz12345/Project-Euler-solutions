from eulerlib import point

n, ans = 1000, 0
for i in range(n):
    p = list(map(int, input().split(',')))
    a, b, c = point(p[0], p[1]), point(p[2], p[3]), point(p[4], p[5])
    ans += abs(point.cross(b - a, c - a)) == abs(point.cross(a, b)) + abs(point.cross(a, c)) + abs(point.cross(b, c))

print(ans)

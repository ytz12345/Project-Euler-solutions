from eulerlib import next_permutation

a, b = [], []
p = [6, 7, 8, 9, 10]

while True:
    a.append([x for x in p])
    if not next_permutation(p):
        break

p = [1, 2, 3, 4, 5]

while True:
    b.append([x for x in p])
    if not next_permutation(p):
        break

ans = 0
for p1 in a:
    for p2 in b:
        if len(set([p1[i] + p2[i] + p2[(i + 1) % 5] for i in range(5)])) == 1:
            st = p1.index(6)
            p3, p4 = p1[st:] + p1[:st], p2[st:] + p2[:st]
            ans = max(ans, int(''.join([str(p3[i]) + str(p4[i]) + str(p4[(i + 1) % 5]) for i in range(5)])))

print(ans)
f = [2, 15, 104]
for i in range(12): f.append(f[-1] * 7 - f[-2] + 1)
print(f[-1])
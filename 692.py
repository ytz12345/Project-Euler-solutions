n = 23416728348467685
f = [1, 2, 3]
s = [1, 3, 6]
while True: 
    f.append(f[-1] + f[-2])
    s.append(s[-1] + f[-1] + s[-2] - f[-3])
    if f[-1] >= n: 
        break
print(s[-1])
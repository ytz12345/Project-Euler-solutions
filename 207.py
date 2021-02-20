from eulerlib import sqrt

def p(x):
    y = int(sqrt(x))
    while y * (y - 1) >  x: y -= 1
    while y * (y + 1) <= x: y += 1

    return (len(bin(y)) - 3, y - 1)

x = 4
while True:
    y = p((x - 1) * (x - 2))
    if y[0] * 12345 < y[1]: break
    x <<= 1

while True:
    y = p((x - 1) * (x - 2))
    if y[0] * 12345 >= y[1]: 
        print(x * (x - 1))
        break
    x -= 1
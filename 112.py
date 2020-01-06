i, j = 99, 0
p, q = 99, 100

def is_inc(x):
    x = str(x)
    n = len(x)
    for i in range(1, n):
        if int(x[i]) < int(x[i - 1]):
            return False
    return True

def is_dec(x):
    x = str(x)
    n = len(x)
    for i in range(1, n):
        if int(x[i]) > int(x[i - 1]):
            return False
    return True

def is_bouncy(x):
    return not is_inc(x) and not is_dec(x)

while j * q < p * i:#j / i < p / q 
    i += 1
    j += is_bouncy(i)

print(i)
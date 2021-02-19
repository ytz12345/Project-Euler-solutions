from math import floor

def f(x): return floor(pow(2, 30.403243784 - x * x)) * 1e-9

x = -1
for i in range(10000): 
    y = x
    x = f(y)

print(x + y)
from eulerlib import next_permutation

def tri(x):return x * (x + 1) // 2
def squ(x):return x * x
def pen(x):return x * (x * 3 - 1) // 2
def hex(x):return x * (x * 2 - 1)
def hep(x):return x * (x * 5 - 3) // 2
def oct(x):return x * (x * 3 - 2)

calc = {3:tri, 4:squ, 5:pen, 6:hex, 7:hep, 8:oct}

def work(p):
    y = []
    for i in p:
        x, j  = [], 1
        while calc[i](j) < 1000:
            j += 1
        while calc[i](j) < 10000:
            x.append(calc[i](j))
            j += 1
        
        if p.index(i) == 0:
            y = [[e] for e in x]
        else:
            z = []
            for a in y:
                for b in x:
                    if str(a[-1])[-2:] == str(b)[:2]:
                        z.append(a + [b])
            
            y = [e for e in z]

    z = []
    for e in y:
        if str(e[-1])[-2:] == str(e[0])[:2]:
            z.append(e)
    
    return z

p = [3, 4, 5, 6, 7, 8]

while True:
    ans = work(p)
    if len(ans) != 0:
        print(sum(*ans))
        break
    
    if not next_permutation(p):
        break
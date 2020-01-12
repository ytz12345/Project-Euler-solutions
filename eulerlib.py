#return p, v for i < n
def get_prime(n): 
    p, v = [0 for i in range(n)], [0 for i in range(n)]
    for i in range(2, n):
        if v[i] == 0:
            p[0] += 1
            p[p[0]] = i 
        for j in range(1, p[0] + 1):
            if i * p[j] >= n:
                break
            v[i * p[j]] = 1
            if i % p[j] == 0:
                break
    return p, v

def digit_sum(x):
    res = 0
    while x != 0:
        res += x % 10
        x //= 10
    return res

class matrix():
    def __init__(self, k = 2):
        self.k = k
        self.c = [[0 for i in range(k)] for i in range(k)]
    
    def __mul__(self, a):
        assert(self.k == a.k)
        b = matrix(self.k)
        for k in range(self.k):
            for i in range(self.k):
                for j in range(self.k):
                    b.c[i][j] += self.c[i][k] * a.c[k][j]
        return b

    def pow(self, k):
        assert(k >= 0)
        
        a = matrix(self.k)
        for i in range(self.k):
            for j in range(self.k):
                a.c[i][j] = self.c[i][j]

        b = matrix(self.k)
        for i in range(self.k):
            b.c[i][i] = 1

        while k > 0:
            if k & 1:
                b = b * a
            a = a * a
            k >>= 1

        return b

def get_divisor(x): #O(sqrt)
    d = []
    i = 1
    while i * i <= x:
        if x % i == 0:
            d.append(i)
            if i * i == x:
                break
            d.append(x // i)
        i += 1
    return d

def c(n, m):
    res, j = 1, 1
    for i in range(n - m + 1, n + 1):
        res *= i
        res //= j
        j += 1
    return res

def is_palindrome(s):
    s = str(s)
    return s == s[::-1]

def is_prime(x):
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

class Roman():
    def __init__(self):
        self.roman_to_int = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        self.w3 = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
        self.w2 = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
        self.w1 = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']

    def get_int_from_roman(self, s):
        v = [self.roman_to_int[i] for i in s]
        for i in range(1, len(v))[::-1]:
            if v[i] > v[i - 1]:
                v[i] -= v[i - 1]
                v[i - 1] = 0
        return sum(v)

    def get_roman_from_int(self, x):
        s = 'M' * (x // 1000)
        x %= 1000

        s += self.w3[x // 100]
        x %= 100

        s += self.w2[x // 10]
        x %= 10

        s += self.w1[x]

        return s

class Poker():
    def __init__(self, s):
        self.num = s[0]
        self.col = s[1]

        if self.num == 'T':
            self.num = 10
        elif self.num == 'J':
            self.num = 11
        elif self.num == 'Q':
            self.num = 12
        elif self.num == 'K':
            self.num = 13
        elif self.num == 'A':
            self.num = 14
        else:
            self.num = int(self.num)

class Poker_Player():
    def __init__(self, pokers):
        self.pokers = pokers
        self.getRank()

    def is_high_card(self):
        self.cmp_val = sorted([poker.num for poker in self.pokers])
        return True

    def is_one_pair(self):
        p = {}
        for poker in self.pokers:
            if poker.num not in p:
                p[poker.num] = 1
            else:
                p[poker.num] += 1

        if len(p) == 4:
            self.cmp_val = sorted([poker.num for poker in self.pokers if p[poker.num] == 1])
            for i in p:
                if p[i] == 2:
                    self.cmp_val.append(i)
            return True
        else:
            return False

    def is_two_pairs(self):
        p = {}
        for poker in self.pokers:
            if poker.num not in p:
                p[poker.num] = 1
            else:
                p[poker.num] += 1

        if sum(p[k] == 2 for k in p) == 2:
            self.cmp_val = sorted([poker.num for poker in self.pokers if p[poker.num] == 2])
            for i in p:
                if p[i] == 1:
                    self.cmp_val = [i] + self.cmp_val
            return True
        else:
            return False

    def is_three_of_a_kind(self):
        p = {}
        for poker in self.pokers:
            if poker.num not in p:
                p[poker.num] = 1
            else:
                p[poker.num] += 1

        if sum(p[k] == 3 for k in p) == 1:
            self.cmp_val = sorted([poker.num for poker in self.pokers if p[poker.num] == 1])
            for i in p:
                if p[i] == 3:
                    self.cmp_val.append(i)
            return True
        else:
            return False

    def is_straight(self):
        self.cmp_val = sorted([poker.num for poker in self.pokers])
        return len(set([poker.num for poker in self.pokers])) == len(self.pokers) and self.cmp_val[-1] - self.cmp_val[0] == len(self.pokers) - 1

    def is_flush(self):
        self.cmp_val = sorted([poker.num for poker in self.pokers])
        return len(set([poker.col for poker in self.pokers])) == 1

    def is_full_house(self):
        p = {}
        for poker in self.pokers:
            if poker.num not in p:
                p[poker.num] = 1
            else:
                p[poker.num] += 1
        
        if len(p) == 2 and (p[self.pokers[0].num] == 2 or p[self.pokers[0].num] == 3):
            self.cmp_val = sorted([poker.num for poker in self.pokers if p[poker.num] == 2])
            for i in p:
                if p[i] == 3:
                    self.cmp_val.append(i)
            return True
        else:
            return False

    def is_four_of_a_kind(self):
        p = {}
        for poker in self.pokers:
            if poker.num not in p:
                p[poker.num] = 1
            else:
                p[poker.num] += 1
        
        if len(p) == 2 and (p[self.pokers[0].num] == 1 or p[self.pokers[0].num] == 4):
            self.cmp_val = sorted([poker.num for poker in self.pokers if p[poker.num] == 1])
            for i in p:
                if p[i] == 4:
                    self.cmp_val.append(i)
            return True
        else:
            return False

    def is_straight_flush(self):
        self.cmp_val = sorted([poker.num for poker in self.pokers])
        return self.is_straight() and self.is_flush()

    def is_royal_flush(self):
        self.cmp_val = sorted([poker.num for poker in self.pokers])
        return self.is_straight_flush() and sorted([poker.num for poker in self.pokers])[0] == 10

    '''[High Card, ..., Royal Flush] -> [0, ..., 9]'''
    def getRank(self):
        judge_method = {
            0:self.is_high_card,
            1:self.is_one_pair,
            2:self.is_two_pairs,
            3:self.is_three_of_a_kind,
            4:self.is_straight,
            5:self.is_flush,
            6:self.is_full_house,
            7:self.is_four_of_a_kind,
            8:self.is_straight_flush,
            9:self.is_royal_flush,
        }
        for i in range(10)[::-1]:
            if judge_method[i]():
                self.rank = i
                break

        return self.rank

    def __gt__(self, another_player):
        if self.rank != another_player.rank:
            return self.rank > another_player.rank
        else:
            for i in range(len(self.cmp_val))[::-1]:
                if self.cmp_val[i] != another_player.cmp_val[i]:
                    return self.cmp_val[i] > another_player.cmp_val[i]

def next_permutation(p):
    n = len(p)
    if sum(p[i] < p[i + 1] for i in range(n - 1)) == 0:
        return False
    
    pos = -1
    for i in range(n - 1)[::-1]:
        if p[i] < p[i + 1]:
            pos = i
            break
    
    for i in range(n)[::-1]:
        if p[i] > p[pos]:
            q = p[:pos] + [p[i]] + p[i + 1:][::-1] + [p[pos]] + p[pos + 1:i][::-1]
            for j in range(n):
                p[j] = q[j]
            return True

def sqr(x):return x * x

def is_sqr(x):
    from math import sqrt
    y = int(sqrt(x))
    return sqr(y - 1) == x or sqr(y) == x or sqr(y + 1) == x 

class point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return point(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return point(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        return self.x * other.x + self.y * other.y

    @staticmethod
    def cross(a, b):
        return a.x * b.y - a.y * b.x

def get_fib(n, Mod = -1):#f1 = f2 = 1, return f[1,...,n]
    f = [0 for i in range(n + 1)]
    f[1] = 1
    for i in range(2, n + 1):
        f[i] = f[i - 1] + f[i - 2]
        if Mod != -1:
            f[i] %= Mod
    return f

def is_pandigital(s):
    s = set(str(s))
    return len(s) == 9 and '0' not in s

#牛顿迭代开根
def sqrt(a, k = 20):
    if a == 0:return 0
    assert a > 0
    x = 1
    for i in range(k):
        x += a / x / 2 - x / 2
    return x

def get_fib_front_k(n, k):
    from math import log
    sqrt_5 = sqrt(5)
    log_fib_n = (n * log((sqrt_5 + 1) / 2) - log(sqrt_5)) / log(10)
    length = int(log_fib_n)
    if length + 1 <= k:
        return int(pow(10, log_fib_n))
    else:
        return int(pow(10, log_fib_n - (length - k + 1)))

#装饰器
class memoize(object):
    def __init__(self, func):
        self.func = func
        self.cache = {}
    
    def __call__(self, *args):
        if args not in self.cache:
            self.cache[args] = self.func(*args)
        return self.cache[args]
        
if __name__ == '__main__':

    @memoize
    def test(x):
        z = 0
        for i in range(10 ** 6):
            z += i * i
        return ((z * z // z + 1) // z)

    from time import time
    print(time())
    print(test(1))
    print(time())
    print(test(1))
    print(time())
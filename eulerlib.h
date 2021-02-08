#include <bits/stdc++.h>

#define pb push_back

using std::vector;
using std::pair;
using std::sort;
using std::unique;
using std::cout;
using std::endl;
using std::map;
using std::cin;
using std::set;
using std::unordered_map;
using std::lower_bound;
using std::max;
using std::ios;
using std::string;
using std::swap;
using std::min;
using std::next_permutation;
using std::make_pair;
using std::bitset;

#define get_inv get_rev //函数alias

typedef unsigned int uint;
typedef long long ll;
typedef pair<int, int> piir;
typedef pair<ll, ll> pr;
typedef vector<pr> vp;
typedef __int128 int128;

ll calc_phi(ll x); //计算phi(x)
ll crt(ll *m, ll *a, int n); //n个式子: y = mx + a, 下标从1开始。返回最小的正数 y = Mx + A
ll euler_power_down(ll c, ll x, ll t, ll p); // (c^(c^(...(c^x))))%p, 套了t次，求结果
void exgcd(ll a, ll b, ll &d, ll &x, ll &y); //x*a+y*b=gcd(a,b)=d
void gauss(vector<vector<long double> > &A, int n); //高消, n个式子，每行n个参数，和1个结果。 结果在A[0...n-1][n]里
ll gcd(ll x, ll y);
void get_ab_from_c(ll c, vector<pr> &v);//传入c, 计算所有无序数对(a,b)使得a^2+b^2=c^2且a>0,b>0
void get_fac(ll n, ll *f);//获取n的所有质因数，有序不重复，f[0]为个数
ll get_palindrome(ll x, int num, bool isOdd);//通过翻转x获取回文数 y=str(x)+str(num)+str(x)[::-1] if isOdd==true; 需要特殊处理回文数[0,9]
void get_phi(int n, int *phi, int *p, int *v);//获取质数的基础上添加了计算欧拉函数
void get_prime(int n, int *p, int *v);//获取小于n的质数放入p,v[i]=1/0表示是/否为质数
int get_repunit(int x); //min(y) for int('1'*y)%x==0, 如果不存在这样的y返回x。负责度O(y)
void get_rev(int n, int *fac, int *inv, int Mod);//获取1-n的阶乘和逆，对Mod取模。需要保证Mod为质数
bool is_ab_sqr_sum_eq_c(ll a, ll b, ll c);// is sqr(a) + sqr(b) == sqr(c)
bool is_prime(ll x);
bool is_sqr(ll x);
void print_time();//输出程序运行时间
ll qpow(ll x, ll k, ll p); // (x^k)%p
template<class T>void sort_and_unique(vector<T> &v);
ll sqr(ll x);


struct Sudoku { //数独，get获取输入
    int sum;
    int used[10];
    int t[10][10];
    char s[10][10];
    piir order[100];
    int pre[10][10][10];

    void get() {
        for (int i = 0; i < 9; i ++) {
            scanf("%s", s[i]);
            for (int j = 0; j < 9; j ++) {
                t[i][j] = s[i][j] - '0';
                pre[i][j][0] = 0;
            }
        }
    }

    bool check(int i, int j) {
        memset (used, 0, sizeof (used));
        for (int k = 0; k < 9; k ++) used[t[i][k]] ++;
        for (int k = 1; k < 10; k ++) if (used[k] > 1) return 0;
        memset (used, 0, sizeof (used));
        for (int k = 0; k < 9; k ++) used[t[k][j]] ++;
        for (int k = 1; k < 10; k ++) if (used[k] > 1) return 0;
        memset (used, 0, sizeof (used));
        for (int k = i / 3 * 3, k_up = k + 3; k < k_up; k ++)
            for (int p = j / 3 * 3, p_up = p + 3; p < p_up; p ++)
                used[t[k][p]] ++;
        for (int k = 1; k < 10; k ++) if (used[k] > 1) return 0;
        return 1;
    }

    bool dfs(int now) {
        if (now == sum) return 1;
        piir no = order[now];
        for (int i = 1; i <= pre[no.first][no.second][0]; i ++) {
            t[no.first][no.second] = pre[no.first][no.second][i];
            if (check(no.first, no.second) && dfs(now + 1)) return 1;
        }
        t[no.first][no.second] = 0;
        return 0;
    }

    bool solve() {
        sum = 0;
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (s[i][j] != '0') continue;
                memset (used, 0, sizeof (used));
                for (int k = 0; k < 9; k ++) {
                    if (s[i][k] != '0') used[s[i][k] - '0'] = 1;
                    if (s[k][j] != '0') used[s[k][j] - '0'] = 1;
                }
                for (int k = i / 3 * 3, k_up = k + 3; k < k_up; k ++)
                    for (int p = j / 3 * 3, p_up = p + 3; p < p_up; p ++)
                        if (s[k][p] != '0') used[s[k][p] - '0'] = 1;
                for (int k = 1; k < 10; k ++)
                    if (!used[k]) pre[i][j][++ pre[i][j][0]] = k;
                order[sum ++] = piir(i, j);
            }
        }

        sort (order, order + sum, [&](piir x, piir y){
            return pre[x.first][x.second][0] < pre[y.first][y.second][0];
        });
        
        return dfs(0);
    }

    void print() {
        for (int i = 0; i < 9; i ++, puts(""))
            for (int j = 0; j < 9; printf("%d", t[i][j ++]));
        puts(""); puts("");
    }
};


void print_time() {
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

ll sqr(ll x) {return x * x;}

bool is_ab_sqr_sum_eq_c(ll a, ll b, ll c) {
    return sqr(a) + sqr(b) == sqr(c);
}

void push_back_first_le_second(vp &v, const pr &p) {
    if (p.first <= p.second) v.pb(p);
    else v.pb(pr(p.second, p.first));
}

void get_ab_from_c_div_k(ll c, ll k, vp &v) {// c = c / k
    for (ll i = 1, j = int(sqrt(c)) + 5; i * i <= c; i ++) {
        while (i * i + j * j > c) j --; if (j <= i) return;
        if (i * i + j * j == c && is_ab_sqr_sum_eq_c(i * j * 2, abs(j * j - i * i), c))
            push_back_first_le_second(v, pr(i * j * 2 * k, abs(j * j - i * i) * k));
    }
}

void get_ab_from_c(ll c, vp &v) {
    v.clear();
    for (ll k = 1; k * k <= c; k ++)
        if (c % k == 0) {
            get_ab_from_c_div_k(c / k, k, v);
            if (k * k != c) get_ab_from_c_div_k(k, c / k, v);
        }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
}

void get_prime(int n, int *p, int *v) {
    p[0] = 0, v[0] = v[1] = 1;
    for (int i = 2; i < n; i ++) {
        if (!v[i]) p[++ p[0]] = i;
        for (int j = 1; j <= p[0] && i * p[j] < n; j ++) {
            v[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void get_phi(int n, int *phi, int *p, int *v) {
    phi[1] = 1;
    for (int i = 2; i < n; i ++) {
        if (!v[i]) phi[i] = i - 1, p[++ p[0]] = i;
        for (int j = 1; j <= p[0] && i * p[j] < n; j ++) {
            v[i * p[j]] = 1;
            if (i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
            else phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
}

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

namespace PollardRho {
    const int T = 20;//测试次数
    ll qmul(ll a, ll b, ll p) {
        ll c = 0;
        for (a %= p; b > 0; b >>= 1) {
            if (b & 1) c += a;
            if (c >= p) c -= p;
            a <<= 1;
            if (a >= p) a -= p;
        }
        return c;
    }
    ll qpow(ll x, ll k, ll p) {
        ll res = 1;
        for (x %= p; k > 0; k >>= 1, x = qmul(x, x, p))
            if (k & 1) res = qmul(res, x, p);
        return res;
    }
    bool check(ll a, ll n, ll x, ll t) {
        ll res = qpow(a, x, n), last = res;
        for (int i = 1; i <= t; i ++) {
            res = qmul(res, res, n);
            if (res == 1 && last != 1 && last != n - 1) return 1;
            last = res;
        }
        if (res != 1) return 1;
        return 0;
    }
    //素数判定函数 (ret = 0) -> prime
    bool millerRabin(ll n) {
        if (n < 2) return 1;
        ll x = n - 1, t = 0;
        while (!(x & 1)) x >>= 1, t ++;
        bool flag = 1;
        if (t >= 1 && (x & 1)) {
            for (int k = 0; k < T; k ++) {
                ll a = rand() % (n - 1) + 1;
                if (check(a, n, x, t)) {
                    flag = 1;
                    break;
                }
                flag = 0;
            }
        }
        if (!flag || n == 2) return 0;
        return 1;
    }
    ll pollardRho(ll x, ll c) {
        ll i = 1, x0 = rand() % x, y = x0, k = 2;
        while (1) {
            i ++;
            x0 = qmul(x0, x0, x) + c % x;
            ll d = abs(gcd(y - x0, x));
            if (d != 1 && d != x) return d;
            if (y == x0) return x;
            if (i == k) y = x0, k <<= 1;
        }
    }
    void findFac(ll n, ll *f) {
        if (!millerRabin(n)) {
            f[++ f[0]] = n;
            return;
        }
        ll p = n;
        while (p >= n) p = pollardRho(p, rand() % (n - 1) + 1);
        findFac(p, f), findFac(n / p, f); 
    }
    //质因数分解函数，因子放在f数组,有重复且无序
    void getFac(ll n, ll *f) {
        f[0] = 0;
        if (n <= 1) return;
        findFac(n, f);
    }
}

bool is_prime(ll x) {
    return !(PollardRho::millerRabin(x));
}

void get_fac(ll n, ll *f) {
    PollardRho::getFac(n, f);
    sort (f + 1, f + f[0] + 1);
    f[0] = unique(f + 1, f + f[0] + 1) - f - 1;
}

std::ostream& operator<<(std::ostream& os, int128 t) {
    if (t==0) return os << "0";
    if (t<0) {
        os<<"-";
        t=-t;
    }
    int a[50],ai=0;
    memset(a,0,sizeof a);
    while (t!=0){
        a[ai++]=t%10;
        t/=10;
    }
    for (int i=1;i<=ai;i++) os<<abs(a[ai-i]);
    return os<<"";
}

void get_rev(int n, int *fac, int *inv, int Mod) {
    fac[0] = 1, inv[0] = 1, inv[1] = 1;
    for (int i = 1; i <= n; i ++) {
        fac[i] = 1ll * fac[i - 1] * i % Mod;
        if (i != 1) inv[i] = 1ll * inv[Mod % i] * (Mod - Mod / i) % Mod;
    }
    for (int i = 2; i <= n; i ++) 
        inv[i] = 1ll * inv[i] * inv[i - 1] % Mod;
}

bool is_sqr(ll x) {
    ll y = sqrt(x);
    return sqr(y - 1) == x || sqr(y) == x || sqr(y + 1) == x; 
}

ll get_palindrome(ll x, int num, bool isOdd = false) {
    static char ch[20]; 
    static ll y;
    ch[0] = y = 0;
    while (x > 0) ch[++ ch[0]] = x % 10, x /= 10;
    for (int i = 1, j = ch[0]; i < j; i ++, j --) swap(ch[i], ch[j]);
    if (isOdd) ch[++ ch[0]] = num;
    for (int i = ch[0] - isOdd; i > 0; i --) ch[++ ch[0]] = ch[i];
    for (int i = 1; i <= ch[0]; i ++) y = y * 10 + ch[i];
    return y;
}

ll qpow(ll x, ll k, ll p) {
    return PollardRho::qpow(x, k, p);
}

template<class T>void sort_and_unique(vector<T> &v) {
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
}

void gauss(vector<vector<long double> > &A, int n) {
    //#define PRINT_A
    #ifdef PRINT_A
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= n; j ++) cout << A[i][j] << ' ';
            cout << endl;
        }
    #endif

	for (int i = 0; i < n; i ++) {
		int r = i;
		for (int j = i + 1; j < n; j ++)
			if(fabs(A[j][i]) > fabs(A[r][i])) 
                r = j;
		if (r != i) 
            for (int j = 0; j <= n; j ++) 
                swap(A[r][j], A[i][j]);

		for(int j = n; j >= i; j --) {
			for(int k = i + 1; k < n; k ++)
				A[k][j] -= A[k][i] / A[i][i] * A[i][j];
		}
	}

	for(int i = n - 1; i >= 0; i --) {
		for(int j = i + 1; j < n; j ++)
			A[i][n] -= A[j][n] * A[i][j];
		A[i][n] /= A[i][i];
	}
}

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        d = a, x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, d, y, x);
    y -= a / b * x;
}
ll crt(ll *m, ll *a, int n) {//n个式子: y = mx + a, 下标从1开始
    ll A = a[1], M = m[1], d, x, y, m2;
    for (int i = 2; i <= n; i ++) {// k1 * m1 - k2 * m2 = a2 - a1
        exgcd(M, m[i], d, x, y);
        if ((a[i] - A) % d) return -1;
        m2 = M / d * m[i];
        x = (a[i] - A) / d * x % m[i];
        A = (A + x * M % m2) % m2;
        if (A < 0) A += m2;//保证A>=0
        M = m2;
    }  
    return A;//y = Mx + A
}

ll euler_power_down(ll c, ll x, ll t, ll p) {
    vector <ll> phi; phi.clear();
    for (phi.pb(p); phi[int(phi.size()) - 1] != 1; )
        phi.pb(calc_phi(phi[int(phi.size()) - 1]));
    phi.pb(1); int tot = phi.size() - 1;
    if (t > tot) {
        if (x >= phi[tot]) x = x % phi[tot] + phi[tot];
        for (int i = tot; i > 0; i --) {
            x = qpow(c, x, phi[i - 1]);
            if (gcd(c, x) != 1) x += phi[i - 1];
        }
        return x % phi[0];
    } else {
        ll phi_p = phi[1];
        for (int i = 1; i <= t; i ++) {
            if (x >= phi_p) x = x % phi_p + phi_p;
            x = qpow(c, x, p);
        }
        return x % p;
    }
}

ll calc_phi(ll x) {
    ll y = x;
    for (ll i = 2; i * i <= x; i ++)
        if (x % i == 0) {
            y /= i;
            y *= i - 1;
            while (x % i == 0) x /= i;
        }
    if (x ^ 1) y /= x, y *= x - 1;
    return y; 
}

int get_repunit(int x) {
    static int f, y[10]; 
    static int sum, i, j, k; sum = f = 0;
    for (i = 0; i < 10; i ++) y[i] = -1;
    for (i = 0; i < 10; i ++) y[x * i % 10] = i;
    for (i = 0; (i + 1) != sum; i ++) {
        j = (1 - f) % 10;
        if (j < 0) j += 10;
        if (y[j] == -1) return 0;
        j = y[j];
        sum += 1 - f;
        f = (f + x * j) / 10; 
        sum += f;  
    }
    return sum;
}
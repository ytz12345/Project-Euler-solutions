#include <bits/stdc++.h>

#define pb push_back

using std::vector;
using std::pair;
using std::sort;

typedef long long ll;
typedef pair<int, int> piir;
typedef pair<ll, ll> pr;
typedef vector<pr> vp;

ll sqr(ll x);
bool is_ab_sqr_sum_eq_c(ll a, ll b, ll c);// is sqr(a) + sqr(b) == sqr(c)
void get_ab_from_c(ll c, vector<pr> &v);//传入c, 计算所有无序数对(a,b)使得a^2+b^2=c^2且a>0,b>0
void get_prime(int n, int *p, int *v);//获取小于n的质数放入p,v[i]=1/0表示是/否为质数
void get_phi(int n, int *phi, int *p, int *v);//获取质数的基础上添加了计算欧拉函数

struct Sudoku {
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
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
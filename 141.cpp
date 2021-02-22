/*
n^2 = q * d + r
=> n^2 - r = q * d

print list
=> r < q < d
=> d = q * q / r
=> n^2 - r = q * d = q^3 / r

for each 1 <= q <= n
find r that q^3 % r == 0 and r < q
then check if q^3 / r + r == n^2
*/

#include "eulerlib.h"

const int N = 1e6 + 1;

int p[N], v[N];

void dfs(ll now, int pos, int lim, const vector<piir> &pd, vector<int> &d) {
    //if (d.size() != 0 && now != d[d.size() - 1]) 
    d.pb(now);
    if (pos >= pd.size()) return;
    if (now * pd[pos].first > lim) return;
    dfs(now, pos + 1, lim, pd, d);
    for (int i = 0; i < pd[pos].second; i ++) {
        now *= pd[pos].first; 
        if (now >= lim) break;
        dfs(now, pos + 1, lim, pd, d);
    }
}

// 给定x的质因数列表pd, 找到x^3所有小于x的因子放到列表d
inline void get_div(const int &x, const vector<piir> &pd, vector<int> &d) {
    d.resize(0);
    dfs(1, 0, x, pd, d);
}

vector <piir> pd[N];

vector <int> d;

set <int> ok;

int main() {
    get_prime(N, p, v);

    for (int i = 1; i <= p[0]; i ++)
        for (int j = p[i]; j <= N; j += p[i]) {
            int t = j, k = 0;
            while (t % p[i] == 0) k ++, t /= p[i];
            pd[j].pb(piir(p[i], k * 3));
        }

    for (int i = 2; i <= N; i ++) {
        ll t = 1ll * i * i * i, y;
        get_div(i, pd[i], d);
        for (int j = 0, s = d.size(); j < s; j ++) {
            if (j != 0 && d[j] == d[j - 1]) continue;
            y = is_sqr(t / d[j] + d[j]);
            if (y != 0 && y * y % i == d[j]) ok.insert(y);
        }
    }
    ll ans = 0;
    for (ll y : ok) {
        if (y >= N) break; 
        ans += y * y;
        //cout << y << endl;
    }
    cout << ans << endl;
    print_time();
}
/*
878454337159
Time elapsed: 7.11505 s.
*/
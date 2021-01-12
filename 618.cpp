#include "eulerlib.h"

const int N = 46400;

const int M = 5200;

const int Mod = 1e9;

int f[30];

int p[N], v[N];

ll ans;

ll mp[M][N];

ll dfs(int pre, ll sum) {
    if (mp[pre][sum] != -1) return mp[pre][sum];
    ll ret = 0;
    int i = pre;
    for (; i > 0 && p[i] > sum; i --);
    for (; i > 0; i --) 
        ret = (ret + p[i] * dfs(i, sum - p[i])) % Mod;
    return mp[pre][sum] = ret;
}

ll calc(ll x) {
    int st;
    for (st = p[0]; p[st] > x; st --);
    ll ret = dfs(st, x);
    if (st <= 0) ret = 0;
    cout << x << ' ' << ret << endl;
    return ret;
}

int main() {
    memset (mp, -1, sizeof mp);
    
    f[1] = f[2] = 1;
    for (int i = 3; i <= 24; i ++) f[i] = f[i - 1] + f[i - 2];//, cout << i << ' ' << f[i] << endl;
    get_prime(N, p, v);

    for (int i = 0; i < M; i ++) mp[i][0] = 1;
    for (int i = 2; i <= 24; i ++)
        ans = (ans + calc(f[i])) % Mod;
    cout << ans << endl;

    print_time();
}
/*
1 0
2 2
3 3
5 11
8 49
13 603
21 25681
34 6595481
55 479486133
89 204414971
144 250497849
233 793019892
377 870685887
610 7837121
987 517955902
1597 760011767
2584 764327681
4181 813949733
6765 342997943
10946 634674116
17711 272019633
28657 652487892
46368 263223866
634212216
Time elapsed: 820.838 s.
*/
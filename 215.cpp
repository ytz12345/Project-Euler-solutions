#include "eulerlib.h"

ll ans;

int n, k;

int start_pos = -2;

vector <int> ok;

vector <ll> dp[2];

void print(int x) {
    for (int j = 0; j + 2 < n; j ++)
            cout << (x >> j & 1);
    cout << endl;
}

void dfs(int now, ll num) {
    if (now > start_pos + n) return;
    if (now == start_pos + n) {
        ok.pb(num ^ (1 << now));
        return;
    }
    dfs(now + 2, num | (1 << (now + 2)));
    dfs(now + 3, num | (1 << (now + 3)));
}

int main() {
    //cin >> n >> k;
    n = 32, k = 10;
    dfs(start_pos, 0);
    
    dp[0].resize(ok.size()), dp[1].resize(ok.size());
    for (int i = 0; i < ok.size(); i ++) dp[0][i] = 1;
    
    for (int now = 1; now < k; now ++) {
        for (int i = 0; i < ok.size(); i ++) dp[now&1][i] = 0;

        for (int i = 0; i < ok.size(); i ++)
            for (int j = 0; j < ok.size(); j ++)
                if ((ok[i] & ok[j]) == 0)
                    dp[now&1][i] += dp[!(now&1)][j];
    }

    for (int i = 0; i < ok.size(); i ++) ans += dp[!(n&1)][i];
    cout << ans << endl;
    print_time();
}
// 806844323190414
// Time elapsed: 0.502633 s.
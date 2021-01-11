#include <bits/stdc++.h>
#include "eulerlib.h"

const int Mod = 1020202009;

const int N = 30000;

int n;

int inv[N], fac[N];

int dp[2][N];

inline void MOD(int &x) {
    while (x >= Mod) x -= Mod; 
    while (x < 0)    x += Mod;
}

inline int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}

int main() {
    cin >> n;
    dp[1][1] = 1;
    getRev(24680, fac, inv, Mod);
    for (int now, i = 2; i <= n; i ++) {
        now = i & 1;
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 1; j <= i; j ++) {
            dp[now][j] = dp[now ^ 1][j - 1];
            for (int k = j + 1, d = 2; k <= i - 1; k += 2, d += 2) {
                dp[now][j] += 1ll * dp[now ^ 1][k] * C(k, d) % Mod;
                MOD(dp[now][j]); 
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) ans = (ans + dp[n & 1][i]) % Mod;
    cout << (ans % Mod + Mod) % Mod << endl;
    return 0;
}
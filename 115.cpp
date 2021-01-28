#include "eulerlib.h"

const int n = 500;

const int m = 50;

ll dp[n + 1][2];

int main() {
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = 0;
        for (int j = m; j <= i; j ++) dp[i][1] += dp[i - j][0];
        if (dp[i][0] + dp[i][1] > 1e6) {
            cout << i << endl;
            print_time();
            return 0;
        }
    }
}
// 168
// Time elapsed: 0.002325 s.
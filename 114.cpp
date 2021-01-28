#include "eulerlib.h"

const int n = 50;

ll dp[n + 1][2];

int main() {
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = 0;
        for (int j = 3; j <= i; j ++) dp[i][1] += dp[i - j][0];
    }
    cout << dp[n][0] + dp[n][1] << endl;
    print_time();
}
// 16475640049
// Time elapsed: 0.001972 s.
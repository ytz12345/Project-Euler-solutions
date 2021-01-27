#include "eulerlib.h"

const int N = 50 + 1;

int a[3] = {2, 3, 4};

ll ans, dp[3][N];

int main() {
    for (int i = 0; i < 3; i ++) {
        dp[i][0] = 1;
        for (int j = 1; j < N; j ++) {
            dp[i][j] = dp[i][j - 1];
            if (j >= a[i]) dp[i][j] += dp[i][j - a[i]];
        }
        ans += dp[i][N - 1] - 1;
    }
    cout << ans << endl;
    print_time();
}
// 20492570929
// Time elapsed: 0.001674 s.
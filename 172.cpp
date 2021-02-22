#include "eulerlib.h"

const int N = 1048576;

int t = 4, n = 18;

ll dp[2][10][N];

ll sum[N], ans;

int main() {
    for (int i = 1; i < 10; i ++) dp[0][i][1 << (i * 2)] = 1;

    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < N; j ++) {
            sum[j] = 0;
            for (int k = 0; k < 10; k ++) sum[j] += dp[!(i&1)][k][j];
        }
        for (int j = 0; j < 10; j ++)
            for (int k = 0; k < N; k ++) {
                dp[i&1][j][k] = 0;
                if (k / (1 << (j * 2)) % 4 == 0) continue;
                dp[i&1][j][k] += sum[k - (1 << (j * 2))];
            }
    }
    for (int i = 0; i < 10; i ++)
        for (int k = 0; k < N; k ++)
            ans += dp[!(n&1)][i][k];

    cout << ans << endl;
    print_time();
}
// 227485267000992000
// Time elapsed: 1.91778 s.
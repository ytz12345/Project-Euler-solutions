#include "eulerlib.h"

ll dp[40][3][3][2], ans;
// 0 -> on time
// 1 -> late
// 2 -> absent

int main() {
    int n = 30;
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int t = 0; t < 3; t ++)
            for (int l1 = 0; l1 < 3; l1 ++)
                for (int l2 = 0; l2 < 3; l2 ++)
                    for (int tt = 0; tt < 2; tt ++) {
                        if (t == 1 && tt == 1) continue;
                        if (t == 2 && l1 == 2 && l2 == 2) continue;
                        dp[i][t][l1][tt | (t == 1)] += dp[i - 1][l1][l2][tt];
                    }
    
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            for (int k = 0; k < 2; k ++)
                ans += dp[n][i][j][k];

    cout << ans << endl;
    print_time();
}
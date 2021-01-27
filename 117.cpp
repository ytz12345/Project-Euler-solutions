#include "eulerlib.h"

const int N = 50 + 1;

int a[4] = {1, 2, 3, 4};

ll dp[N] = {1};

int main() {
    for (int i = 1; i < N; i ++) {
        dp[i] = 0;
        for (int j = 0; j < 4; j ++)
            if (i >= a[j]) dp[i] += dp[i - a[j]];
    }
    cout << dp[N - 1] << endl;
    print_time();
}
// 100808458960497
//Time elapsed: 0.003762 s.
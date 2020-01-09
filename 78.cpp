#include "eulerlib.h"

const int N = 100000;
const int Mod = 1e6;

int dp[N];

int main() {
    dp[0] = 1;
    for (int i = 1; i < N; i ++) {
        for (int j = i; j < N; j ++) {
            dp[j] += dp[j - i];
            if (dp[j] >= Mod) dp[j] -= Mod;
        }
        if (dp[i] == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
}
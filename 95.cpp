#include "eulerlib.h"

const int N = 1e6;

int f[N + 1], g[N + 1], h[N + 1];

int len, ans;

int main() {
    for (int i = 1; i < N; i ++)
        for (int j = i + i; j <= N; j += i)
            f[j] += i;
    for (int k, j, i = 1; i <= N; i ++) {
        j = i, k = 0;
        while (j <= N && g[j] != i) 
            g[j] = i, h[j] = k ++, j = f[j];
        if (j <= N) {
            if (k - h[j] == len) ans = std::min(ans, j);
            else if (k - h[j] > len) len = k - h[j], ans = j;
        }
    }
    std::cout << len << " " << ans << '\n';
}
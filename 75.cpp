#include "eulerlib.h"

const int N = 1500001;

int cnt[N];

int main() {
    vector <pr> v;
    int n = N / 2, ans = 0;
    for (int i = 1; i <= n; i ++) {
        get_ab_from_c(i, v);
        for (pr p : v) 
            if (p.first + p.second + i < N)
                cnt[p.first + p.second + i] ++;
    }
    for (int i = 1; i < N; i ++)
        if (cnt[i] == 1)
            ans ++;
    std::cout << ans << '\n';
    return 0;
}
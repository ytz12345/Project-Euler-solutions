#include "eulerlib.h"

const ll N = 1e8;

ll sum_sqr[10001];

bool judge(ll x) {
    for (int i = lower_bound(sum_sqr + 1, sum_sqr + 10001, x) - sum_sqr; i <= 10000; i ++) {
        if (i * i > x) break;
        if (sum_sqr[i] == x) return 1;
        int j = lower_bound(sum_sqr + 1, sum_sqr + 10001, sum_sqr[i] - x) - sum_sqr;
        if (j + 1 != i && sum_sqr[i] - sum_sqr[j] == x) return 1;
    }
    return 0;
}

int main() {
    ll x, ans = 5;
    for (int i = 1; i <= 10000; i ++) sum_sqr[i] = sum_sqr[i - 1] + i * i;
    for (int i = 1; i <= 10000; i ++) {
        x = get_palindrome(i, 0, 0);
        if (x > N) break;
        if (judge(x)) ans += x;
        for (int j = 0; j < 10; j ++) {
            x = get_palindrome(i, j, 1);
            if (x > N) break;
            if (judge(x)) ans += x;
        }
    }
    cout << ans << endl;
    print_time();
}
// 2906969179
// Time elapsed: 17.2501 s.
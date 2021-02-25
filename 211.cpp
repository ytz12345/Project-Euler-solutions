#include "eulerlib.h"

const int N = 64e6;

ll sum[N], tmp, ans;

int main() {
    for (int i = 1; i < N; i ++) {
        tmp = sqr(ll(i));
        for (int j = i; j < N; j += i) 
            sum[j] += tmp;
    }
    for (int i = 1; i < N; i ++)
        if (is_sqr(sum[i]))
            ans += i;

    cout << ans << endl;
    print_time();
}
// 1922364685
// Time elapsed: 18.2226 s.
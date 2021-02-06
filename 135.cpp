#include "eulerlib.h"

const int N = 1e6 + 1;

vector <int> d[N];

int ans;

int main() {
    for (int i = 1; i < N; i ++)
        for (int j = i; j < N; j += i) 
            d[j].pb(i);

    for (int i = 1; i < N; i ++) {
        int cnt = 0;
        for (int x : d[i]) {
            int k = i / x + x;
            if (k % 4 != 0) continue;
            k /= 4;
            if (k >= x) continue;
            cnt ++;
        }
        if (cnt != 0) {
            //cout << i << ' ' << cnt << endl;
            if (cnt == 10) ans ++;
        }
    }
    cout << ans << endl;
    print_time();
}
// 4989
// Time elapsed: 4.00471 s.
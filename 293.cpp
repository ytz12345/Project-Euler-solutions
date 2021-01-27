#include "eulerlib.h"

const int lim = 1e9;

int p[10] = {9, 2, 3, 5, 7, 11, 13, 17, 19, 23};

set <int> s;

ll ans;

void dfs(int id, ll now) {
    if (now != 1) {
        for (int i = 3; ; i += 2) 
            if (is_prime(now + i)) {
                s.insert(i);
                break;
            }
    }
    if (id > p[0]) return;
    for (int i = 1; ; i ++) {
        now *= p[id];
        if (now > lim) break;
        dfs(id + 1, now);
    }
}

int main() {
    dfs(1, 1);
    for (int x : s) ans += x;
    cout << ans << endl;
    print_time();
}
// 2209
// Time elapsed: 2.17232 s.
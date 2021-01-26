#include "eulerlib.h"

int ans = 2 * 2 * 2 * 2 * 2 * 2 * 2 * 3 * 3 * 5 * 5 * 7 * 11 * 13 * 17;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; 

void dfs(int id, ll now, ll sum, int lim) {
    if (now > ans) return;
    if (sum > 1999) {ans = now; return;}
    if (id >= 10) return;
    for (int i = 2; i <= lim; i += 2) dfs(id + 1, now *= p[id], sum * (i + 1), i);
}

int main() {
    dfs(0, 1, 1, 50);
    cout << ans << endl;
    print_time();
}
// 180180
// Time elapsed: 0.00233 s.

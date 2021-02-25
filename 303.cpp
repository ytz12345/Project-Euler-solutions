#include "eulerlib.h"

const int N = 1e4 + 1;
const int lim = 20;

int no_ans[N];

ll ans;

void dfs(int now, ull nb) {
    if (now > lim) {
        if (nb == 0) return;

        static int i, t; 
        for (i = 1, t = no_ans[0], no_ans[0] = 0; i <= t; i ++) {
            if (nb % no_ans[i] == 0) ans += nb / no_ans[i];
            else no_ans[++ no_ans[0]] = no_ans[i];
        }

        if (no_ans[0] == 0) {
            cout << ans << endl;
            print_time(); 
            exit(0);
        }

        return;
    }
    dfs(now + 1, nb * 10 + 0);
    dfs(now + 1, nb * 10 + 1);
    dfs(now + 1, nb * 10 + 2);
}

int main() {
    no_ans[0] = N - 1;
    for (int i = 1; i < N; i ++) no_ans[i] = i;

    dfs(1, 0); 
}
// 1111981904675169
// Time elapsed: 21.8989 s.
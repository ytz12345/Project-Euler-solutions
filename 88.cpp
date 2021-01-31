#include "eulerlib.h"

const int N = 12000 + 1;

vector <int> ans;

int sum = 0;

int pw2[20];

void dfs(int now, int up, ll c, int s) {
    if (c * pw2[up - now + 1] >= N * 2) return;
    if (now > up) {
        int pos = c - s + up;
        if (pos < N) ans[pos] = min(ans[pos], int(c));
        return;
    }
    for (int i = 2; ; i ++) {
        if (c * i * pw2[up - now] >= N * 2) return;
        dfs(now + 1, up, c * i, s + i);
    }
}

int main() {
    ans.resize(N);
    for (int i = 2; i < N; i ++) ans[i] = i * 2;
    for (int i = 0; i < 20; i ++) pw2[i] = 1 << i;

    for (int m = 2; m <= 14; m ++) {// 2^14 > N
        dfs(1, m, 1, 0);
    }

    ans[0] = ans[1] = ans[2];
    sort_and_unique(ans);
    for (int x : ans) sum += x;
    cout << sum << endl;
    print_time();
}
// 7587457
// Time elapsed: 0.126418 s.
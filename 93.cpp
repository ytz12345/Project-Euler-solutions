#include "eulerlib.h"

const int lim = 10;
const int N = 10000;
const double eps = 1e-8;

int ans[4], max_n, temp_n;

int vis[N], arr[4];

vector <double> cc[4][4];

int double2int(double x) {
    static int y; y = x;
    if (abs(x-y) < eps) return y; y-=1;
    if (abs(x-y) < eps) return y; y+=2;
    if (abs(x-y) < eps) return y;
    return -1;
}

void calc() {
    static int y;
    while (1) {
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++)
                cc[i][j].clear();

        for (int i = 0; i < 4; i ++) cc[i][i].pb(arr[i]);
        for (int d = 1; d < 4; d ++)
            for (int i = 0; i + d < 4; i ++) {
                int j = i + d;
                for (int k = i; k < j; k ++) 
                    for (double x : cc[i][k])
                        for (double y : cc[k + 1][j]) {
                            cc[i][j].pb(x + y);
                            cc[i][j].pb(x - y);
                            cc[i][j].pb(x * y);
                            if (y != 0) cc[i][j].pb(x / y);
                        }
                sort_and_unique(cc[i][j]);
            }
        for (double x : cc[0][3]) if ((y=double2int(x)) > 0) vis[y] = 1;
        if (!next_permutation(arr, arr + 4)) break;
    }
}

int main() {
    for (arr[0] = 1; arr[0] <= lim; arr[0] ++)
        for (arr[1] = arr[0] + 1; arr[1] <= lim; arr[1] ++)
            for (arr[2] = arr[1] + 1; arr[2] <= lim; arr[2] ++)
                for (arr[3] = arr[2] + 1; arr[3] <= lim; arr[3] ++) {
                    memset(vis, 0, sizeof vis);
                    calc();
                    temp_n = 0;
                    for (int i = 1; ; i ++) {
                        if (!vis[i]) break;
                        temp_n = i;
                    }
                    if (temp_n > max_n) {
                        max_n = temp_n;
                        ans[0] = arr[0], ans[1] = arr[1], ans[2] = arr[2], ans[3] = arr[3];
                    }
                }
    for (int i = 0; i < 4; i ++) cout << ans[i];
    cout << ' ' << max_n << endl;
    print_time();
}
// 1258 51
// Time elapsed: 0.151021 s.
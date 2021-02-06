#include "eulerlib.h"

const int N = 7;

const int eps = 4;

int a[N] = {20, 31, 38, 39, 40, 42, 45}, b[7];

int s = 1e9;

bool check(int *a, int n = N) {
    int sum[1 << n], cnt[1 << n];
    for (int i = 1, j = (1 << n) - 1; i < j; i ++) {
        sum[i] = cnt[i] = 0;
        for (int j = 0; j < n; j ++) {
            if (i >> j & 1) {
                cnt[i] ++;
                sum[i] += a[j];
            } 
        } 
    }
    for (int i = 1; i < (1 << n); i ++)
        for (int j = i + 1; j < (1 << n); j ++) {
            if (sum[i] == sum[j]) return 0;
            if (cnt[i] > cnt[j]) {
                if (sum[i] < sum[j]) return 0;
            } else if (cnt[i] < cnt[j]) {
                if (sum[i] > sum[j]) return 0;
            }
        }

    return 1;
}

void dfs(int now, int sum) {
    if (now >= N) {
        if (sum < s && check(a)) {
            s = sum;
            for (int i = 0; i < N; i ++) b[i] = a[i];
        }
        return;
    }
    int re = a[now];
    for (int i = re - eps; i <= re + eps; i ++)
        a[now] = i, dfs(now + 1, sum + i);
    a[now] =re;
}

int main() {
    dfs(0, 0);
    for (int i = 0; i < N; i ++) cout << b[i];
    cout << endl << s << endl;
    print_time();
}
// 20313839404245 255
// Time elapsed: 13.7776 s.
#include "eulerlib.h"

const int N = 201;

struct bsn {
    bitset<N> x;

    int operator [](const int &index) {
        return x[index];
    }

    bool operator < (const bsn &a) const {
        for (int i = 0; i < N; i ++)
            if (x[i] != a.x[i])
                return x[i] < a.x[i];
        return 1;
    }

    bool operator == (const bsn &a) const {
        for (int i = 0; i < N; i ++)
            if (x[i] != a.x[i])
                return 0;
        return 1;
    }
};

set<bsn> a[N];

int ans[N], sum_ans;

int main() {
    ans[1] = 1;
    bsn a1; a1.x[1]=1; a[1].insert(a1);
    for (int i = 2; i < N; i ++) {
        ans[i] = i;
        for (int j = (i + 1) / 2; j < i; j ++) {
            if (ans[j] + 1 > ans[i]) continue;
            for (bsn b : a[j]) {
                if (b[i - j] == 1) {
                    if (ans[j] + 1 < ans[i]) {
                        ans[i] = ans[j] + 1;
                        a[i].clear();
                    }
                    b.x[i] = 1; a[i].insert(b);
                }
            }
        }
    }
    for (int i = 1; i < N; i ++) sum_ans += ans[i] - 1;
    cout << sum_ans << endl;
    print_time();
}
// 1582
// Time elapsed: 0.146497 s.
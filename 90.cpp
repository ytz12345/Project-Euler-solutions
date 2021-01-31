#include "eulerlib.h"

const int p2w10 = 1024;

int cnt[p2w10], ans;

int sr[9][2] = {
    0, 1,
    0, 4,
    0, 9, 
    1, 6,
    2, 5,
    3, 6,
    4, 9,
    6, 4, 
    8, 1
};

void f(int &x) {
    if ((x >> 6) & 1) x |= 1 << 9;
    if ((x >> 9) & 1) x |= 1 << 6;
}

bool check(int x, int y) {
    f(x), f(y);

    for (int i = 0; i < 9; i ++) {
        bool ok = 0;
        if (((x >> sr[i][0]) & 1) && ((y >> sr[i][1]) & 1)) ok = 1;
        swap(x, y);
        if (((x >> sr[i][0]) & 1) && ((y >> sr[i][1]) & 1)) ok = 1;
        if (!ok) return 0;
    }
    return 1;
}

int main() {
    for (int i = 0; i < p2w10; i ++) {
        int c = 0;
        for (int x = i; x; x >>= 1) c += x & 1;
        cnt[i] = c;
    }

    for (int i = 0; i < p2w10; i ++) if (cnt[i] == 6)
        for (int j = i; j < p2w10; j ++) if (cnt[j] == 6)
            ans += check(i, j);
        
    cout << ans << endl;
    print_time();
}
// 1217
// Time elapsed: 0.005879 s.
#include "eulerlib.h"

int128 n = 1, pw2[100];

typedef pair<int, int128> pii1r;

map<pii1r, int128> cnt;

int128 dfs(int now, int128 sum) {
    pii1r p8r = pii1r(now, sum);

    if ((pw2[now + 1] - 1) * 2 < sum) return cnt[p8r] = 0;
    if (cnt.find(p8r) != cnt.end()) return cnt[p8r];

    if (sum == 0) {
        return cnt[p8r] = 1;
    } if (now == 0) {
        return cnt[p8r] = 1;     
    } else {
        int128 res = 0;
        for (int128 i = 0, j = min(sum / pw2[now], int128(2)); i <= j; i ++) 
            res += dfs(now - 1, sum - pw2[now] * i);
        return cnt[p8r] = res;
    }
}

int main() {
    pw2[0] = 1;
    for (int i = 1; i < 100; i ++) pw2[i] = pw2[i - 1] * 2; 
    for (int i = 0; i < 25; i ++) n *= 10;
    // 100001000101100101010001011000010100000000010100100001001010000000000000000000000000
    cout << dfs(83, n) << endl;
    print_time();
}
// 178653872807
// Time elapsed: 0.005417 s.
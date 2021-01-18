#include "eulerlib.h"

const ll  N = 1e16;
const int Mod = 1e9 + 7;

int ans, pw2 = 500000004;

int main() {
    ans = 0; 
    int i, blk_md;
    ll start, blk, pos;
    for (i = 1, start = 0; ; i ++) {
        start += i;
        if (start > N) break;
        blk = (N - start + 1) / i;
        blk_md = blk % Mod;
        ans += 1ll * blk_md * (blk_md + 1) % Mod * i % Mod * pw2 % Mod;
        while (ans >= Mod) ans -= Mod;
        ans += (N - (blk * i + start) + 1) * (blk_md + 1) % Mod;
        while (ans >= Mod) ans -= Mod;
    }
    cout << ans << endl;
    print_time();
}
// 110941813
// Time elapsed: 9.90362 s.
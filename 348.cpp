#include "eulerlib.h"

const ll N = 1e10;

ll rev(int x, int num, bool isOdd = false) {
    static char ch[20]; 
    static ll y;
    ch[0] = y = 0;
    while (x > 0) ch[++ ch[0]] = x % 10, x /= 10;
    for (int i = 1, j = ch[0]; i < j; i ++, j --) swap(ch[i], ch[j]);
    if (isOdd) ch[++ ch[0]] = num;
    for (int i = ch[0] - isOdd; i > 0; i --) ch[++ ch[0]] = ch[i];
    for (int i = 1; i <= ch[0]; i ++) y = y * 10 + ch[i];
    return y;
}

bool judge(ll x) {
    int cnt = 0;
    for (ll i = 1, j; ; i ++) {
        j = i * i * i;
        if (j >= x) break;
        if (is_sqr(x - j)) cnt ++;
    }
    return cnt == 4;
}

int main() {
    ll x, ans = 0;
    for (int i = 1; i <= 10000; i ++) {
        x = rev(i, 0, 0);
        if (x > N) break;
        if (judge(x)) ans += x;
        for (int j = 0; j < 10; j ++) {
            x = rev(i, j, 1);
            if (x > N) break;
            if (judge(x)) ans += x;
        }
    }
    cout << ans << endl;
    print_time();
}
// 1004195061
// Time elapsed: 0.847673 s.
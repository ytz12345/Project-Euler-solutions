#include "eulerlib.h"

bool check(ll x, int b) {
    for (int i = b - 1; i > 1; i --)
        if (!is_pandigital(x, i))
            return 0;
    return 1;
}

ll arr2int(const vector<int> &a) {
    static ll ret; ret = 0;
    for (int i = 0, s = a.size(); i < s; i ++) ret = ret * s + a[i];
    return ret;
}

int main() {
    vector <int> a;
    int n, k = 10;
    ll ans = 0, x;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i ++) a[i] = i;
    swap(a[0], a[1]);

    do {
        if (check(x = arr2int(a), n)) {
            ans += x, k --;//, cout << x << endl;
            if (k <= 0) break;
        }
    }while (next_permutation(a.begin(), a.end()));

    cout << ans << endl;
    print_time();
}
// 1587937206284
// 1674839888205
// 2638904175622
// 2806980157234
// 2816957039424
// 3325871906940
// 3863090145827
// 3909765781284
// 3925260871994
// 3960783529164

// 30510390701978
// Time elapsed: 640.316 s.
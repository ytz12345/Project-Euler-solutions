#include "eulerlib.h"

int main() {
    int n = 100, ans = 0, s, k;
    vector <int> v;
    for (int i = 0; i < n; i ++) {
        cin >> k; 
        v.resize(k), s = 0;
        for (int j = 0; j < k; j ++) cin >> v[j], s += v[j];
        if (is_set_special(v)) ans += s;
    }
    cout << ans << endl;
    print_time();
}
// 73702
// Time elapsed: 0.651353 s.
#include "eulerlib.h"

int num = 30;

ll lim = 1e18;

vector <ll> ans;

bool check(ll x, ll y) {
    while (x != 0) y -= x % 10, x /= 10;
    return y == 0;
}

int main() {
    for (ll i = 2; i <= 100; i ++) {
        if (sqr(i) > lim) break;
        for (ll j = i * i; j <= lim; j *= i) 
            if (check(j, i)) 
                ans.push_back(j);
    }    
    sort (ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans[num - 1] << endl;
    print_time();
}

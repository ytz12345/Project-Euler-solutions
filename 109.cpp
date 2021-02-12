#include "eulerlib.h"

const int lim = 100;

vector <int> v, d;

int main() {
    for (int i = 1; i <= 20; i ++) v.pb(i), v.pb(i * 2), v.pb(i * 3), d.push_back(i * 2);
    v.pb(25), v.pb(50); sort(v.begin(), v.end()); d.push_back(50);
    
    int ans = 0;
    
    for (int x : d) ans += x < lim;
    
    for (int x : v) for (int y : d) ans += x + y < lim;

    for (int x = 0; x < v.size(); x ++)
        for (int y = x; y < v.size(); y ++)
            for (int z : d)
                ans += v[x] + v[y] + z < lim;  

    cout << ans << endl;
    print_time();
}
// 38182
// Time elapsed: 0.004735 s.
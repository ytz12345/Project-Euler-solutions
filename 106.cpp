#include "eulerlib.h"

const int n = 12;

vector <int> v[1 << n];

int ans;

int main() {
    for (int i = 0; i < (1 << n); i ++) 
        for (int j = 0; j < n; j ++)
            if (i >> j & 1)
                v[i].pb(j);
    for (int i = 1; i < (1 << n); i ++)
        for (int j = i + 1; j < (1 << n); j ++) {
            if (v[i].size() != v[j].size()) continue;
            if (v[i][0] > v[j][v[j].size() - 1] || v[j][0] > v[i][v[i].size() - 1]) continue;
            
            bool have_same = 0;
            for (int x = 0, y = 0; x < v[i].size(); x ++) {
                while (y < v[j].size() && v[j][y] < v[i][x]) y ++;
                if (y < v[j].size() && v[j][y] == v[i][x]) {
                    have_same = 1;
                    break;
                }
            }
            if (have_same) continue;

            int flag = 0;
            for (int x = 0; x < v[i].size(); x ++) {
                if (v[i][x] > v[j][x]) flag |= 1;
                if (v[i][x] < v[j][x]) flag |= 2;
            }

            if (flag != 3) continue;

            ans ++;
        }
    cout << ans << endl;
    print_time();
}
// 21384
// Time elapsed: 0.124237 s.
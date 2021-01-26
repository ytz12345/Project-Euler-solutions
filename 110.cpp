#include "eulerlib.h"

int128 ans = 1;

const int prime_num = 20;

int p[prime_num] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71}; 

int N = 4e6;

void dfs(int id, int128 now, int128 sum, int lim) {
    if (now > ans) return;
    if (sum >= N * 2) {ans = now; return;}
    if (id >= prime_num) return;
    for (int i = 2; i <= lim; i += 2) dfs(id + 1, now *= p[id], sum * (i + 1), i);
}

int main() {
    ans *= qpow(2, 15, 1e18);
    ans *= qpow(3, 7, 1e18);
    ans *= qpow(5, 3, 1e18);
    for (int i = 3; i < 17; i ++) ans *= p[i];
    
    dfs(0, 1, 1, 50);
    cout << ans << endl;
    print_time();
}
// 9350130049860600
// Time elapsed: 0.00372 s.
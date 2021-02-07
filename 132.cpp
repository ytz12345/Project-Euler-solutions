#include "eulerlib.h"

const int N = 1e6 + 1;

const int L = 1e9;

int p[N], v[N];

int ans, cnt;

bool check(int x) {
    static int f, y[10]; 
    static int sum, i, j, k; sum = f = 0;
    for (i = 0; i < 10; i ++) y[i] = -1;
    for (i = 0; i < 10; i ++) y[x * i % 10] = i;
    for (i = 0; (i + 1) != sum; i ++) {
        j = (1 - f) % 10;
        if (j < 0) j += 10;
        if (y[j] == -1) return 0;
        j = y[j];
        sum += 1 - f;
        f = (f + x * j) / 10; 
        sum += f;  
    }
    return L % sum == 0;
}

int main() {
    get_prime(N, p, v);
    for (int i = 5; i <= p[0] && cnt < 40; i ++) 
        if (check(p[i])) 
            ans += p[i], cnt ++;
    cout << ans << ' ' << cnt << endl;
    print_time();
}
// 843296 40
// Time elapsed: 13.2556 s.
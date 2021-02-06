#include "eulerlib.h"

unordered_map <int, bool> is_p;

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int c[10], ans, A = 1;

bool check_prime(int x) {
    if (is_p.find(x) != is_p.end()) return is_p[x];
    return is_p[x] = is_prime(x);
}

void dfs(int now, int index, int num) {
    if (now >= 9) {
        c[index + 1] += check_prime(num);
        return;
    }
    dfs(now + 1, index, num * 10 + a[now]);
    if (num != 0 && check_prime(num)) dfs(now + 1, index + 1, a[now]);
}

int main() {
    do {
        if (a[8] == 4 || a[8] == 6 || a[8] == 8) continue;
        if (a[8] == 2 && (a[7] == 4 || a[7] == 6 || a[7] == 8)) continue;
        if (a[8] == 5 && (a[7] == 4 || a[7] == 6 || a[7] == 8)) continue;
        dfs(0, 0, 0);
    } while (next_permutation(a, a + 9));
    for (int i = 1; i < 10; i ++) {
        A *= i;
        ans += c[i] / A;
        if (c[i] % A != 0) cout << i << ' ' << c[i] << endl;
    }
    cout << ans << endl;
    print_time();
}
// 44680
// Time elapsed: 10.1426 s.
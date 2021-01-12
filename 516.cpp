#include "eulerlib.h"

ll N = 1e12;

uint ans;

vector <ll> prime;

int a[3] = {2, 3, 5};

void dfs(ll now, int i) {
    if (i >= 3) return;
    while (1) {
        dfs(now, i + 1);
        if (now + 1 <= N && is_prime(now + 1)) prime.push_back(now + 1);
        if (now * a[i] > N) break;
        now *= a[i];
    }
}

void redfs(ll now, int id, ll last) {
    static ll x, y, z;
    if (now != last) {
        for (x = now; x <= N; x *= 2)
            for (y = x; y <= N; y *= 3)
                for (z = y; z <= N; z *= 5)
                    ans += z;
    }
    if (id >= prime.size()) return;
    if (now > N / prime[id]) return;
    redfs(now, id + 1, now);
    redfs(now * prime[id], id + 1, now);
}

int main() {
    //cin >> N;
    dfs(1, 0);
    sort (prime.begin(), prime.end());
    prime.resize(unique (prime.begin(), prime.end()) - prime.begin());

    // #define PRINT_PRIME
    #ifdef  PRINT_PRIME
        cout << prime.size() << endl;
        for (int i = 0; i < prime.size(); i++) {
            cout << prime[i] << ' ';
        }
    cout << endl;
    return 0;
    #endif

    redfs(1, 3, 0);
    cout << ans << endl;
    return 0;
}
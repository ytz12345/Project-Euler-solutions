#include "eulerlib.h"

const int N = 1e5 + 1;

int p[N], v[N];

vector <int> fac[N];

struct node{int id, num;}a[N];

int main() {
    v[1] = 1;
    for (int i = 2; i < N; i ++) {
        if (v[i]) continue;
        for (int j = i; j < N; j += i) {
            v[j] = 1;
            fac[j].push_back(i);
        }
    }
    for (int i = 1; i < N; i ++) {
        a[i].id = i;
        a[i].num = 1;
        for (int j : fac[i])
            a[i].num *= j;
    }
    sort (a + 1, a + N, [&](node x, node y){return x.num != y.num ? x.num < y.num : x.id < y.id;});
    cout << a[10000].id << endl;
    print_time();
}
// 21417
// Time elapsed: 0.110607 s.
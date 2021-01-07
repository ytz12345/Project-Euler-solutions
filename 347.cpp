#include <bits/stdc++.h>
#include "eulerlib.h"

typedef long long ll;

const int N = 1e7 + 1;

const int BN = 1e6;

int p[N], v[N];

int small_prime[N], large_prime[N];

ll ans;

#define mid ((l + r) >> 1)
#define lc  (o << 1)
#define rc  (lc | 1)

struct node {
    ll min_pos, min_value, sum;
}tr[N << 2];

void update(int o) {
    static int son;
    son = tr[rc].min_value < tr[lc].min_value ? rc : lc;
    tr[o].min_pos = tr[son].min_pos;
    tr[o].min_value = tr[son].min_value;
}

void build(int o, int l, int r) {
    if (l == r) {
        tr[o].min_value = small_prime[r];
        tr[o].sum = 0;
        tr[o].min_pos = r;
        return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    update(o);
}

void add(int o, int l, int r, int p) {
    if (l == r) {
        if (tr[o].min_value != small_prime[p]) {
            tr[o].sum -= tr[o].min_value / small_prime[p];
        }
        tr[o].sum += tr[o].min_value;
        tr[o].min_value *= small_prime[p];
        return;
    }
    if (p <= mid) add(lc, l, mid, p);
    else          add(rc, mid + 1, r, p);
    update(o);
    tr[o].sum = tr[lc].sum + tr[rc].sum;
}

void get_big_ans() {
    build(1, 1, small_prime[0]);

    for (int i = large_prime[0]; i > 0; i --) {
        while (tr[1].min_value * large_prime[i] < N) 
            add(1, 1, small_prime[0], tr[1].min_pos);
        //printf("%d %lld\n", large_prime[i], tr[1].sum);
        ans += tr[1].sum * large_prime[i];
    }
}

ll calc(ll x, ll y) {
    if (x * y >= N) return 0;
    ll z = x * y;
    while (z * x < N) z *= x;
    ll ret = z, tmp_z, tmp_y = 1;
    while (true) {
        z /= x;
        if (z % x != 0) break;
        tmp_z = z;
        while (tmp_z * tmp_y * y < N) tmp_y *= y;
        ret = std::max(ret, tmp_z * tmp_y); 
    }
    // printf("%lld %lld %lld\n", x, y, ret);
    return ret;
}

void get_small_ans() {
    for (int i = 1; i < small_prime[0]; i ++) 
        for (int j = i + 1; j <= small_prime[0]; j ++) 
            ans += calc(small_prime[i], small_prime[j]);
}

int main() {
    get_prime(N / 2 + 1, p, v);

    small_prime[0] = large_prime[0] = 0;;
    for (int i = 1; i <= p[0]; i ++) {
        if (1ll * p[i] * p[i] < N) small_prime[++ small_prime[0]] = p[i];
        else                       large_prime[++ large_prime[0]] = p[i];
    }

    // printf("%d %d %d\n", small_prime[0], large_prime[0], p[0]);
    // 446 664133 664579
    
    get_small_ans();
    // printf("small_ans=%lld\n", ans);
    get_big_ans();

    printf("%lld\n", ans);
}
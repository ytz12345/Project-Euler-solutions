#include <bits/stdc++.h>

using namespace std;

typedef __int128 int128;

typedef long long ll;

const int N = 1e6 + 1;

const ll M = 1e18;

vector <int> a[N];

int p[N], v[N], u[N];

int128 ans = M;

ostream& operator<<(std::ostream& os, __int128 t) {
    if (t==0) return os << "0";
    if (t<0) {
        os<<"-";
        t=-t;
    }
    int a[50],ai=0;
    memset(a,0,sizeof a);
    while (t!=0){
        a[ai++]=t%10;
        t/=10;
    }
    for (int i=1;i<=ai;i++) os<<abs(a[ai-i]);
    return os<<"";
}

unordered_map<ll, bool>mp;
void dfs(ll st, vector<int> x) {
    mp[st]=1;
    ans += M / st;
    for (ll y : x) {
        if (st <= M / y && !mp[st * y]) {
            dfs(st * y, x);
        }
    }
}

int main() {
    for (int i = 2; i < N; i ++)
        u[i] = 1;
    for (int i = 2; i < N; i ++) {
        if (v[i]) continue;
        a[i].push_back(i);
        for (int j = i + i; j < N; j += i) {
            a[j].push_back(i);
            v[j] = 1;
        }
        if (i >= N / i) continue;
        for (int k = i * i, j = k; j < N; j += k) {
            u[j] = 0;
            a[j].clear();
        }
    }

    /*
    for (int i = 1; i <= 100; i ++) {
        if (u[i]) {
            cout << i << '\n';
            for (int j : a[i])
                cout << j << ' ';
            cout << '\n';
        }
    }
    */

    ll cub, tmp, temp;
    for (int i = 2; i < N; i ++) {
        if (!u[i]) continue;
        cub = 1ll * i * i * i;
        mp.clear();
        dfs(cub, (a[i]));
        //cout << i << ' ' << ans << endl;
    }

    cout << ans << endl;
    return 0; 
}
//13344
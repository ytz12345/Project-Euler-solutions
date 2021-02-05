#include "eulerlib.h"

const int N = 1786;

unordered_map<string, vector<string> > mp;

unordered_map<char, int> used;

vector <ll> sqrs[20];

ll ans, i2ch[10];

bool match(ll x, string str) {
    used.clear();
    memset(i2ch, 0, sizeof i2ch);

    for (int i = int(str.size()) - 1; i >= 0; i --) {
        int j = x % 10; x /= 10;
        if (used.find(str[i]) == used.end() && i2ch[j] == 0) {
            used[str[i]] = j, i2ch[j] = str[i];
        } else {
            return 0;
        }
    }

    return used[str[0]] != 0;
}

ll isSqr(string str) {
    static ll res; res = 0;
    for (char ch : str) res = res * 10 + used[ch];
    return (used[str[0]] != 0 && is_sqr(res)) ? res : 0;
}

int main(){
    ios::sync_with_stdio(false);
    
    sqrs[1].pb(0);
    for (ll i = 0; i < 100000; i ++) {
        ll j = i * i, len = 0;
        while (j > 0) len ++, j /= 10;
        sqrs[len].pb(i * i);
    }

    string str, strCopy;
    set <char> chs;
    for (int i = 0; i < N; i ++) {
        cin >> str; strCopy = str;
        chs.clear(); for (char ch : str) chs.insert(ch);
        if (chs.size() > 10) continue;

        sort(str.begin(), str.end());
        mp[str].push_back(strCopy);
    }

    for (auto pr : mp) {
        if (pr.second.size() < 2) continue;

        str = pr.second[0];
        for (ll x : sqrs[str.size()]) {
            if (!match(x, str)) continue;
            bool allSqr = 1;
            for (int i = 1; i < pr.second.size(); i ++)
                if (!isSqr(pr.second[i])) {
                    allSqr = 0;
                    break;
                }
            if (!allSqr) continue;

            for (int i = 0; i < pr.second.size(); i ++)
                ans = max(ans, isSqr(pr.second[i]));
            break;
        }
    }

    cout << ans << endl;
    print_time();

    return 0;
}

// 18769
// Time elapsed: 0.108567 s.
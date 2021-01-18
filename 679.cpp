// 对半拆，各自处理，再缝合
#include "eulerlib.h"

const char *list = "aefr";

char s[20];

ll ans, cnt[64][16], rev[64][16];

string strs[] = {"free", "fare", "area", "reef"};
string strss[] = {"eerf", "eraf", "aera", "feer"};

int char2int(char ch) {
    for (int i = 0; i < 4; i ++) 
        if (list[i] == ch) 
            return i;
    abort();
    return -1;
}

void dfs(int now, int *c, int pos, int id) {
    if (now == 15) {
        cnt[pos][id] ++;
        return;
    }
    int new_pos, new_id, flag, cc[4];
    for (int i = 0; i < 4; i ++) {
        s[now] = list[i];
        if (now < 3) {
            new_pos = pos * 4 + char2int(s[now]);
        } else {
            new_pos = pos;
        }
        flag = true; new_id = id;
        for (int j = 0; j < 4; j ++) {
            cc[j] = c[j];
            if (s[now] == strs[j][c[j]]) {
                cc[j] ++;
                if (cc[j] == 4) {
                    if ((id & (1 << j)) != 0) flag = false;
                    new_id |= 1 << j;
                    cc[j] = 0;
                    if (s[now] == strs[j][0]) cc[j] = 1;
                }
            } else if (s[now] != strs[j][0]) {
                cc[j] = 0;
            } else {
                cc[j] = 1;
            }
        }
        if (flag) dfs(now + 1, cc, new_pos, new_id);
    }
}

void rev_dfs(int now, int *c, int pos, int id) {
    if (now == 15) {
        rev[pos][id] ++;
        return;
    }
    int new_pos, new_id, flag, cc[4];
    for (int i = 0; i < 4; i ++) {
        s[now] = list[i];
        if (now < 3) {
            new_pos = pos * 4 + char2int(s[now]);
        } else {
            new_pos = pos;
        }
        flag = true; new_id = id;
        for (int j = 0; j < 4; j ++) {
            cc[j] = c[j];
            if (s[now] == strss[j][c[j]]) {
                cc[j] ++;
                if (cc[j] == 4) {
                    if ((id & (1 << j)) != 0) flag = false;
                    new_id |= 1 << j;
                    cc[j] = 0;
                    if (s[now] == strss[j][0]) cc[j] = 1;
                }
            } else if (now > 0 && s[now - 1] == strss[j][0] && s[now] == strss[j][1]) {
                cc[j] = 2;
            } 
            else if (s[now] == strss[j][0]) {
                cc[j] = 1;
            } else {
                cc[j] = 0;
            }
        }
        if (flag) rev_dfs(now + 1, cc, new_pos, new_id);
    }
}

int calc(int x, int y) {
    static char str[10];
    str[0] = list[x % 4]; x /= 4;
    str[1] = list[x % 4]; x /= 4;
    str[2] = list[x % 4];

    str[5] = list[y % 4]; y /= 4;
    str[4] = list[y % 4]; y /= 4;
    str[3] = list[y % 4];

    int res = 0;
    for (int i = 0; i <= 2; i ++)
        for (int j = 0; j < 4; j ++) {
            int k = 0;
            for (; k < 4 && strs[j][k] == str[i + k]; k ++);
            if (k == 4) {
                res |= 1 << j;
            }
        }
    return res;
}

int main() {
    int c[] = {0, 0, 0, 0};
    dfs(0, c, 0, 0);
    rev_dfs(0, c, 0, 0);

    for (int x = 0; x < 16; x ++) 
        for (int y = 0; y < 16; y ++) {
            if ((x & y) != 0) continue;
            int z = x | y;

            for (int i = 0; i < 64; i ++) 
                for (int j = 0; j < 64; j ++) {
                    int k = calc(i, j);
                    if ((k & z) == 0 && (k | z) == 15) ans += rev[i][x] * cnt[j][y];
                }
        }
    cout << ans << endl;
    print_time();
}
// 644997092988678
// Time elapsed: 110.967 s
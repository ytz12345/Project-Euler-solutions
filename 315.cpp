#include "eulerlib.h"

const int N = 1e7;
const int NN = 2e7 + 1;

int p[NN], v[NN], st;

ll sum_sam, sum_max;

/* 
 2
1 3
 4
5 7
 6 
*/

int arr[10][8];

int calc_one(int x) {
    int ret = 0;
    while (x != 0) ret += arr[x % 10][0], x /= 10;
    return ret;
}

int calc_change(int x, int y) {
    int ret = 0;
    static int a, b;
    //cout << x << ' ' << y << ' ';
    while (x != 0 && y != 0) {
        a = x % 10, b = y % 10;
        for (int j = 1; j < 8; j ++)
            ret += arr[a][j] ^ arr[b][j];
        x /= 10, y /= 10;
    }
    return ret + calc_one(x + y );
}

int next_num(int x) {
    if (x < 10) return 0;
    int ret = 0;
    while (x != 0) ret += x % 10, x /= 10;
    return ret;
}

void calc_ans(int x, ll &ans_first, ll &ans_second) {
    static int sum_1, sum_2; sum_1 = sum_2 = 0;
    for (int j = x; j != 0; sum_1 += calc_one(j) * 2, j = next_num(j));
    for (int j = x, last = 0; !(last == 0 && j == 0); sum_2 += calc_change(last, j), last = j, j = next_num(j));
    //cout << sum_1 << ' ' << sum_2 << endl;
    ans_first += sum_1; ans_second += sum_2;
}

int main() {
    // init
    arr[0][1] = arr[0][2] = arr[0][3] = arr[0][5] = arr[0][6] = arr[0][7] = 1;
    arr[1][3] = arr[1][7] = 1;
    arr[2][2] = arr[2][3] = arr[2][4] = arr[2][5] = arr[2][6] = 1;
    arr[3][2] = arr[3][3] = arr[3][4] = arr[3][6] = arr[3][7] = 1;
    arr[4][1] = arr[4][3] = arr[4][4] = arr[4][7] = 1;
    arr[5][1] = arr[5][2] = arr[5][4] = arr[5][6] = arr[5][7] = 1;
    arr[6][1] = arr[6][2] = arr[6][4] = arr[6][5] = arr[6][6] = arr[6][7] = 1;
    arr[7][1] = arr[7][2] = arr[7][3] = arr[7][7] = 1;
    arr[8][1] = arr[8][2] = arr[8][3] = arr[8][4] = arr[8][5] = arr[8][6] = arr[8][7] = 1;
    arr[9][1] = arr[9][2] = arr[9][3] = arr[9][4] = arr[9][6] = arr[9][7] = 1;

    for (int i = 0; i < 10; i ++)
        for (int j = 1; j < 8; j ++)
            arr[i][0] += arr[i][j];

    get_prime(NN, p, v);
    for (st = 1; p[st] < N; st ++);
    // cout << st << ' ' << p[0] << ' ' <<p[0] - st << endl; 

    //calc_ans(137, sum_sam, sum_max); return 0;

    for (int i = st; i <= p[0]; i ++) {
        //if (i % 10000 == 0) cout << i << endl;
        calc_ans(p[i], sum_sam, sum_max);
    }
    cout << sum_sam - sum_max << endl;
}
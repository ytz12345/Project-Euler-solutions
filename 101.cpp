#include "eulerlib.h"

int128 f(int128 n) {
    return ((((n * n + 1) * n * n + 1) * n * n + 1) * n * n + 1) * (n * n - n) + 1;
}

int128 arr[15], ans = 1;

vector <vector<long double> > a;

int128 longdouble2int128(long double x) {
    if (x < 0) {
        return int128(x - 0.5);
    }
    
    return int128(x + 0.5);
}

int main() {
    a.resize(15); 
    for (int i = 0; i < 15; i ++) a[i].resize(15);

    int128 tmp, tmp_ans;
    for (int i = 2; i <= 10; i ++) {
        for (int j = 0; j < i; j ++) {
            tmp = 1;
            for (int k = 0; k < i; k ++) {
                a[j][k] = tmp;
                tmp *= j + 1;
            }
            a[j][i] = f(j + 1);
        }

        gauss(a, i); 
        for (int j = 0; j < i; j ++) 
            arr[j] = longdouble2int128(a[j][i]);
        for (int j = 1; j <= i + 1; j ++) {
            tmp_ans = 0; tmp = 1;
            for (int k = 0; k < i; k ++) {
                tmp_ans += arr[k] * tmp;
                tmp *= j; 
            }
            cout << tmp_ans << ' ';
        }
        cout << endl;
        ans += ll(tmp_ans + 0.5); 
    }

    cout << ans << endl;
    print_time();
}
// 37076114526
// Time elapsed: 0.002296 s.
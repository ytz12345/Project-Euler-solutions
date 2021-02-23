#include "eulerlib.h"

#define r(x) for (x = 0; x <= 9; x ++)
#define c(x) (x < 0 || x > 9)

int a[4][4], sum, ans;

int main() {
    r(a[0][3]) r(a[1][2]) r(a[2][1]) r(a[3][0]) {
        sum = a[0][3] + a[1][2] + a[2][1] + a[3][0];
        r(a[0][0]) r(a[0][1]) r(a[1][0]) r(a[1][1]) r(a[2][2]) {
            a[0][2] = sum - a[0][0] - a[0][1] - a[0][3]; if (c(a[0][2])) continue;
            a[2][0] = sum - a[0][0] - a[1][0] - a[3][0]; if (c(a[2][0])) continue;
            a[3][3] = sum - a[0][0] - a[1][1] - a[2][2]; if (c(a[3][3])) continue;
            a[1][3] = sum - a[1][0] - a[1][1] - a[1][2]; if (c(a[1][3])) continue;
            a[2][3] = sum - a[2][0] - a[2][1] - a[2][2]; if (c(a[2][3])) continue;
            if ((a[0][3] + a[1][3] + a[2][3] + a[3][3]) ^ sum) continue;

            a[3][1] = sum - a[0][1] - a[1][1] - a[2][1]; if (c(a[3][1])) continue;
            a[3][2] = sum - a[0][2] - a[1][2] - a[2][2]; if (c(a[3][2])) continue;
            if ((a[3][0] + a[3][1] + a[3][2] + a[3][3]) ^ sum) continue;
            
            ans ++;
        }
    }

    cout << ans << endl;
    print_time();
}
// 7130034
// Time elapsed: 3.41215 s.
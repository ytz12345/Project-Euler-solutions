#include "eulerlib.h"

const int N = 1e6;

int calc(int x) {
    static int f, y[10]; 
    static int sum, i, j, k; sum = f = 0;
    for (i = 0; i < 10; i ++) y[i] = -1;
    for (i = 0; i < 10; i ++) y[x * i % 10] = i;
    for (i = 0; (i + 1) != sum; i ++) {
        j = (1 - f) % 10;
        if (j < 0) j += 10;
        if (y[j] == -1) return 0;
        j = y[j];
        sum += 1 - f;
        f = (f + x * j) / 10; 
        sum += f;  
    }
    return sum;
}

int main() {
    // A(n) <= n
    for (int i = N + 1; ; i += 2) {
        if (i % 5 != 0 && calc(i) > N) {
            cout << i << endl;
            print_time();
            return 0;
        }
    }
}
// 1000023
// Time elapsed: 0.043954 s.
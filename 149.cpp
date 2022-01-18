#include <time.h>
#include <vector>
#include <iostream>
#include "eulerlib.h"

int main() {
    typedef long long int64; 

    int N = 4e6;
    std::vector<int> s(N+1, 0); 
    for (int i = 1; i <= 55; i ++) {
        s[i] = (int64(100003) - int64(i) * 200003 + int64(i) * int64(i) * int64(i) * 300007) % 1000000 - 500000;
    }
    for (int i = 55 + 1; i <= N; i ++) {
        s[i] = (s[i-24] + s[i-55] + 1000000) % 1000000 - 500000;
    }

    N = 2e3;
    std::vector<std::vector<int> > a(N, std::vector<int>(N));
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            a[i][j] = s[i * N + j + 1];
    
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < N; i ++) {
        tmp = 0;
        for (int j = 0; j < N; j ++) tmp += a[i][j], tmp = std::max(tmp, 0);
        ans = std::max(ans, tmp);
        tmp = 0;
        for (int j = 0; j < N; j ++) tmp += a[j][i], tmp = std::max(tmp, 0);
        ans = std::max(ans, tmp);
    }

    for (int j = -N; j < N; j ++) {
        // start from (0, j)
        tmp = 0;
        for (int i = 0; i < N; i ++) {
            if (0 <= i+j && i+j < N) {
                tmp += a[i][i+j], tmp = std::max(tmp, 0);
            }
        }
        ans = std::max(ans, tmp);
    }

    for (int j = 0; j < N + N; j ++) {
        // start from (0, j)
        tmp = 0;
        for (int i = 0; i < N; i ++) {
            if (0 <= j-i && j-i < N) {
                tmp += a[i][j-i], tmp = std::max(tmp, 0);
            }
        }
        ans = std::max(ans, tmp);
    }

    std::cout << ans << std::endl;
    print_time();
    return 0;
}

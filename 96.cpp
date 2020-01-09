#include "eulerlib.h"

Sudoku s;

int main() {
    int ans = 0, T = 50;
    while (T --) {
        scanf("%*s %*d");
        s.get();
        printf("%d\n", s.solve());
        ans += s.t[0][0] * 100 + s.t[0][1] * 10 + s.t[0][2];
    }
    printf("%d\n", ans);
}
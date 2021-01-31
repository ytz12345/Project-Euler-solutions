#include "eulerlib.h"

const int lim = 1818; // mid search

int sum;

int main() {
    for (int a = 1; a <= lim; a ++)
        for (int b = a; b <= lim; b ++)
            for (int c = b; c <= lim; c ++)
                if (is_sqr(sqr(a + b) + sqr(c)))
                    sum ++;
    cout << sum << endl;
    print_time();
}
// 1000457
// Time elapsed: 13.3542 s.
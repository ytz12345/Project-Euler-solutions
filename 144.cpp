#include "computational_geometry.h"

void calc_next(line &l) {
    static line r, k; 
    r.p[0] = k.p[0] = l.p[1];
    
    if (cmp(l.p[1].y, 0) != 0) k.p[1] = point(0, 100.0 / l.p[1].y);
    else                       k.p[1] = point(0, 0);

    k.p[1] = k.p[0] + (k.p[1] - k.p[0]).turn90();
    r.p[1] = reflect(k.p[0], k.p[1], l.p[0]);

    static double A, B, C;
    A = 4 * sqr(r.p[1].x - r.p[0].x) + sqr(r.p[1].y - r.p[0].y);
    B = 4 * (2 * r.p[0].x * (r.p[1].x - r.p[0].x)) + 2 * r.p[0].y * (r.p[1].y - r.p[0].y);
    C = 4 * sqr(r.p[0].x) + sqr(r.p[0].y) - 100;

    static pdd pd;
    pd = get_equation_solution(A, B, C).second;

    static point p1, p2;
    p1 = r.p[0] + (r.p[1] - r.p[0]) * pd.first;
    p2 = r.p[0] + (r.p[1] - r.p[0]) * pd.second;

    if (inmid(r.p[0], r.p[0], p1)) r.p[1] = p2;
    else {
        assert(inmid(r.p[0], r.p[0], p2));
        r.p[1] = p1;
    }

    l = r; 
}

int main() {
    line now = line(point(0.0, 10.1), point(1.4, -9.6));

    int ans = 0;
    while (!(inmid(-0.01, 0.01, now.p[1].x) && now.p[1].y > 0)) {
        ans ++;
        calc_next(now);
        now.p[0].print();now.p[1].print();
    }

    cout << ans << endl;
    print_time();
}
// 354
// Time elapsed: 0.003778 s.
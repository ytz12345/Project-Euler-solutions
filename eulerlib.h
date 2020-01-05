void get_prime(int n, int *p, int *v) {
    p[0] = 0, v[0] = v[1] = 1;
    for (int i = 2; i < n; i ++) {
        if (!v[i]) p[++ p[0]] = i;
        for (int j = 1; j <= p[0] && i * p[j] < n; j ++) {
            v[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void get_phi(int n, int *phi, int *p, int *v) {
    for (int i = 2; i < n; i ++) {
        if (!v[i]) phi[i] = i - 1, p[++ p[0]] = i;
        for (int j = 1; j <= p[0] && i * p[j] < n; j ++) {
            v[i * p[j]] = 1;
            if (i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
            else phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
}
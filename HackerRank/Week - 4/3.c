#define MOD 1000000007

long long modpow(long long base, int exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int legoBlocks(int n, int m) {
    static long long row[1001], total[1001], valid[1001];
    static int initialized = 0;

    if (!initialized) {
        row[0] = 1;
        for (int i = 1; i <= 1000; i++) {
            row[i] = 0;
            for (int k = 1; k <= 4; k++) {
                if (i - k >= 0) row[i] = (row[i] + row[i - k]) % MOD;
            }
        }
        initialized = 1;
    }
     for (int i = 1; i <= m; i++) {
        total[i] = modpow(row[i], n);
    }

    for (int i = 1; i <= m; i++) {
        long long tmp = total[i];
        for (int k = 1; k < i; k++) {
            tmp = (tmp - valid[k] * total[i - k]) % MOD;
            if (tmp < 0) tmp += MOD;
        }
        valid[i] = tmp;
    }

    return (int)valid[m];
}
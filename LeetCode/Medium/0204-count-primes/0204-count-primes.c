#include <stdlib.h>

int countPrimes(int n) {
    if (n <= 2) return 0;

    int count = 0;

    // 0..n-1 aralığını tutuyoruz
    char *primes = (char*)malloc(n * sizeof(char));
    if (!primes) return 0;

    for (int i = 0; i < n; i++) primes[i] = 1;
    primes[0] = primes[1] = 0;

    for (int i = 2; (long long)i * i < n; i++) {
        if (primes[i]) {
            for (long long j = (long long)i * i; j < n; j += i) {
                primes[j] = 0;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (primes[i]) count++;
    }

    free(primes);
    return count;
}
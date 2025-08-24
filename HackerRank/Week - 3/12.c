int* generate_primes(int q) {
    int *primes = malloc(q * sizeof(int));
    int count = 0, num = 2;
    while (count < q) {
        int ok = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                ok = 0;
                break;
            }
        }
        if (ok) primes[count++] = num;
        num++;
    }
    return primes;
}

int* waiter(int number_count, int* number, int q, int* result_count) {
    int *result = malloc(number_count * sizeof(int));
    int res_idx = 0;
    int *primes = generate_primes(q);

    int *A = malloc(number_count * sizeof(int));
    int A_size = number_count;
    for (int i = 0; i < number_count; i++) A[i] = number[i];

    for (int i = 0; i < q; i++) {
        int prime = primes[i];
        int *next_a = malloc(number_count * sizeof(int));
        int next_a_size = 0;
        int *b = malloc(number_count * sizeof(int));
        int b_size = 0;

        for (int j = A_size - 1; j >= 0; j--) {
            if (A[j] % prime == 0) b[b_size++] = A[j];
            else next_a[next_a_size++] = A[j];
        }
        for (int j = b_size - 1; j >= 0; j--) result[res_idx++] = b[j];

        free(A);
        A = next_a;
        A_size = next_a_size;
        free(b);
    }
    for (int j = A_size - 1; j >= 0; j--) result[res_idx++] = A[j];

    free(A);
    free(primes);

    *result_count = res_idx;
    return result;
}
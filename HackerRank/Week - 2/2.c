void sortArray(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void findZigZagSequence(int a[], int n) {
    sortArray(a, n);
    int mid = (n + 1) / 2 - 1;
    int temp = a[mid];
    a[mid] = a[n - 1];
    a[n - 1] = temp;
    int st = mid + 1;
    int ed = n - 2;
    while (st <= ed) {
        temp = a[st];
        a[st] = a[ed];
        a[ed] = temp;
        st++;
        ed--;
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%d\n", a[i]);
        else
            printf("%d ", a[i]);
    }
}
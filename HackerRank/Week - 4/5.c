void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_up(int *heap, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[i] < heap[p]) {
            swap(&heap[i], &heap[p]);
            i = p;
        } else break;
    }
}

void heapify_down(int *heap, int n, int i) {
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, s = i;
        if (l < n && heap[l] < heap[s]) s = l;
        if (r < n && heap[r] < heap[s]) s = r;
        if (s != i) {
            swap(&heap[i], &heap[s]);
            i = s;
        } else break;
    }
}

int extract_min(int *heap, int *n) {
    if (*n == 0) return -1;
    int min = heap[0];
    heap[0] = heap[--(*n)];
    heapify_down(heap, *n, 0);
    return min;
}

void insert(int *heap, int *n, int val) {
    heap[(*n)++] = val;
    heapify_up(heap, *n - 1);
}

int cookies(int k, int A_count, int* A) {
    int n = 0;
    for (int i = 0; i < A_count; i++) insert(A, &n, A[i]);

    int ops = 0;
    while (n > 0 && A[0] < k) {
        if (n < 2) return -1;
        int first = extract_min(A, &n);
        int second = extract_min(A, &n);
        int mixed = first + 2 * second;
        insert(A, &n, mixed);
        ops++;
    }
    return ops;
}

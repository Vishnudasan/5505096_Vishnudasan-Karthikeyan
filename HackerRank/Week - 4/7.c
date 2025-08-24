int* solve(int arr_count, int* arr, int queries_count, int* queries, int* result_count) {
    int n = arr_count;
    int *left = malloc(n * sizeof(int));
    int *right = malloc(n * sizeof(int));
    int *st = malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[st[top]] <= arr[i]) top--;
        left[i] = (top == -1 ? -1 : st[top]);
        st[++top] = i;
    }

    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && arr[st[top]] < arr[i]) top--;
        right[i] = (top == -1 ? n : st[top]);
        st[++top] = i;
    }

    int *best = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) best[i] = INT_MAX;

    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        if (arr[i] < best[len]) best[len] = arr[i];
    }

    for (int w = n - 1; w >= 1; w--) {
        if (best[w] > best[w + 1]) best[w] = best[w + 1];
    }

    int *ans = malloc(queries_count * sizeof(int));
    for (int i = 0; i < queries_count; i++) {
        int q = queries[i];
        if (q < 1) q = 1;
        if (q > n) q = n;
        ans[i] = best[q];
    }

    *result_count = queries_count;
    free(left); free(right); free(st); free(best);
    return ans;
}

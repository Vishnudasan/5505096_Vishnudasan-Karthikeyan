long arrayManipulation(int n, int queries_rows, int queries_columns, int** queries) {
    long *arr = calloc(n+2, sizeof(long));
    for(int i = 0; i < queries_rows; i++){
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];
        arr[a] += k;
        if (b + 1 <= n){
            arr[b + 1] -= k;
    }
    }
    long maxVal = 0, current = 0;
    for (int i = 1; i <= n; i++) {
        current += arr[i];
        if (current > maxVal){
            maxVal = current;
    }
}
    free(arr);
    return maxVal;
}
typedef struct {
    int value;
    int index;
} Pair;

int cmpasc(const void *a, const void *b) {
    Pair *p1 = (Pair*)a;
    Pair *p2 = (Pair*)b;
    return p1->value - p2->value;
}

int cmpdesc(const void *a, const void *b) {
    Pair *p1 = (Pair*)a;
    Pair *p2 = (Pair*)b;
    return p2->value - p1->value;
}

int countSwaps(int *arr, int n, int order) {
    Pair *pairs = (Pair*)malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        pairs[i].value = arr[i];
        pairs[i].index = i;
    }

    if (order == 0) {
        qsort(pairs, n, sizeof(Pair), cmpasc);
    } else {
        qsort(pairs, n, sizeof(Pair), cmpdesc);
    }
    int *visited = (int*)calloc(n, sizeof(int));
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || pairs[i].index == i) {
            continue;
        }

        int cycleSize = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = 1;
            j = pairs[j].index;
            cycleSize++;
        }

        if (cycleSize > 1) {
            swaps += cycleSize - 1;
        }
    }

    free(pairs);
    free(visited);
    return swaps;
}
int lilysHomework(int arr_count, int* arr) {
    int ascswaps = countSwaps(arr, arr_count, 0);
    int descswaps = countSwaps(arr, arr_count, 1);
    return ascswaps < descswaps ? ascswaps : descswaps;
}
int* maxSubarray(int arr_count, int* arr, int* result_count) {
    *result_count = 2;
    int* result = malloc(2 * sizeof(int));

    int max_ending_here = arr[0];
    int max_so_far = arr[0];

    for (int i = 1; i < arr_count; i++) {
        if (max_ending_here + arr[i] > arr[i]) {
            max_ending_here = max_ending_here + arr[i];
        } else {
            max_ending_here = arr[i];
        }
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }
    }
    int subseq_sum = 0;
    int is_positive = 0;
    int max_elem = arr[0];
    for (int i = 0; i < arr_count; i++) {
        if (arr[i] > 0) {
            subseq_sum += arr[i];
            is_positive = 1;
        }
        if (arr[i] > max_elem) {
            max_elem = arr[i];
        }
    }
        if (!is_positive) {
        subseq_sum = max_elem;
    }

    result[0] = max_so_far;
    result[1] = subseq_sum;
    return result;
}
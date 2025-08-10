int* countingSort(int arr_count, int* arr, int* result_count) {
    *result_count = 100;
    int *frequency = calloc(100, sizeof(int));
    for(int i = 0;i<arr_count;i++){
        frequency[arr[i]]++;
    }
    return frequency;
}

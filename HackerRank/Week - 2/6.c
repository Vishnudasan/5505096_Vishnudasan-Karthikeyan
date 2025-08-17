int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
 }

int maxMin(int k, int arr_count, int* arr) {
    qsort(arr, arr_count, sizeof(int),compare);
    
    int min_unfairness = INT_MAX;
    
    for(int i=0; i<= arr_count-k;i++){
        int diff = arr[i+k-1] - arr[i];
        if(diff < min_unfairness){
            min_unfairness = diff;
        }
    }
    return min_unfairness;
}
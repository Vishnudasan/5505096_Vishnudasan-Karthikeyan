char* balancedSums(int arr_count, int* arr) {
    static char yes[] = "YES";
    static char no[] = "NO";
    
    long long total_sum = 0;
    long long left_sum = 0;
    
    for(int i = 0; i<arr_count; i++){
        total_sum += arr[i];
    }
    
    for(int i = 0; i<arr_count; i++){
        long long right_sum = total_sum - left_sum - arr[i];
        if(left_sum == right_sum){
            return yes;
        }
        left_sum += arr[i];
    }
    return no;
}

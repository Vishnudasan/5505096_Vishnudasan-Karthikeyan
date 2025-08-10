int birthday(int s_count, int* s, int d, int m) {
    int ways = 0;
    
    for(int i=0; i<=s_count-m; i++){
        int sum = 0;
        for(int j=0; j<m; j++){
            sum += s[i+j];
        }
        if(sum == d){
            ways++;
        }
    }
    return ways;
}

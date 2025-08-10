int cmpascending(const void *a,const void *b){
    return (*(int*)a - *(int*)b);
 }
 int cmpdescending(const void *a,const void *b){
    return (*(int*)b - *(int*)a);  
 }
char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    qsort(A, A_count,sizeof(int),cmpascending);
    qsort(B, B_count,sizeof(int),cmpdescending);
    
    for(int i = 0;i<A_count;i++){
        if (A[i]+B[i] < k) {
            return "NO";
        
        }
    }
    return "YES";
}
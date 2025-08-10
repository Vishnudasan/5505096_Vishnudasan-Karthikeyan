int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    int* results = malloc(queries_count*sizeof(int));
    
    for(int i=0;i<queries_count;i++){
        int count = 0;
        for(int j=0;j<strings_count;j++){
            if(strcmp(queries[i], strings[j])==0){
                count++;
            }
        }
        results[i] = count;
    }
    *result_count = queries_count;
    return results;
}
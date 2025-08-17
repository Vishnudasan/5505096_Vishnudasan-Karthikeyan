int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int **sequencelist = malloc(n * sizeof(int*));
    int *sequencesize = calloc (n, sizeof(int));
    int *sequencecap = calloc(n, sizeof(int));
    
    int* results = malloc(queries_rows* sizeof(int));
    int resultcount = 0;
    int lastanswer = 0;
    for(int i = 0; i<queries_rows;i++){
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x^lastanswer)%n;
        
        if(type == 1){
            if (sequencecap[idx] == 0){
                sequencecap[idx] =2;
                sequencelist[idx] = malloc(sequencecap[idx] * sizeof(int));
            }
            else if (sequencesize[idx] == sequencecap[idx]){
                sequencecap[idx] *= 2;
                sequencelist[idx] = realloc(sequencelist[idx], sequencecap[idx] * sizeof(int));
            }
            sequencelist[idx][sequencesize[idx]++] = y;    
            }
            else if(type == 2){
                int position = y % sequencesize[idx];
                lastanswer = sequencelist[idx][position];
                 results[resultcount++] = lastanswer;
            }
        }
        *result_count = resultcount;
        return results;
    }
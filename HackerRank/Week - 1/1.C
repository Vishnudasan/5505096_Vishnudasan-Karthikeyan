#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(int arr_count, int* arr) {
    int positive = 0, negative = 0, zero = 0;
    
    for(int i =0;i<arr_count;i++){
        if (arr[i] >0){
            positive++;
        }
    else if (arr[i] < 0) {
        negative++;
    
    }
    else{
        zero++;
    }
    }
    printf("%.6f\n", (float)positive / arr_count);
    printf("%.6f\n", (float)negative / arr_count);
    printf("%.6f\n", (float)zero / arr_count);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000

typedef struct {
    int type;
    char *data;
} Operation;

int main() {
    int Q;
    scanf("%d", &Q);

    char *S = calloc(MAX_LEN, sizeof(char));
    int len = 0;

    Operation *stack = malloc(Q * sizeof(Operation));
    int top = -1;

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char temp[100000];
            scanf("%s", temp);
            int tlen = strlen(temp);
            strcpy(S + len, temp);
            len += tlen;

            stack[++top].type = 1;
            stack[top].data = strdup(temp);

        } else if (type == 2) {
            int k;
            scanf("%d", &k);

            char *deleted = malloc((k + 1) * sizeof(char));
            strncpy(deleted, S + len - k, k);
            deleted[k] = '\0';

            len -= k;
            S[len] = '\0';

            stack[++top].type = 2;
            stack[top].data = deleted;

        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);

        } else if (type == 4) {
            if (top >= 0) {
                Operation last = stack[top--];
                if (last.type == 1) {
                    int tlen = strlen(last.data);
                    len -= tlen;
                    S[len] = '\0';
                } else if (last.type == 2) {
                    int tlen = strlen(last.data);
                    strcpy(S + len, last.data);
                    len += tlen;
                }
                free(last.data);
            }
        }
    }

    free(S);
    free(stack);
    return 0;
}

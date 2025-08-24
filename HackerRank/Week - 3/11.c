char* isBalanced(char* s) {
    static char yes[] = "YES";
    static char no[] = "NO";
    int n = strlen(s);
    char *stack = malloc(n);
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) {
                free(stack);
                return no;
            }
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return no;
            }
        }
    }

    free(stack);
    return top == -1 ? yes : no;
}
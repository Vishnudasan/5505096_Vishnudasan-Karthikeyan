static char** alloc_grid(int r, int c, char fill) {
    char** g = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        g[i] = malloc(c + 1);
        for (int j = 0; j < c; j++) g[i][j] = fill;
        g[i][c] = '\0';
    }
    return g;
}
static char** copy_grid(char** src, int r, int c) {
    char** g = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        g[i] = malloc(c + 1);
        memcpy(g[i], src[i], c + 1);
    }
    return g;
}
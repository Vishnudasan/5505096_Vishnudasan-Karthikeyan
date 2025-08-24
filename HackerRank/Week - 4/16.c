long roadsAndLibraries(int n, int c_lib, int c_road, int cities_rows, int cities_columns, int** cities) {
    if (c_lib <= c_road){
        return (long)n * c_lib;
    }

    int* visited = calloc(n + 1, sizeof(int));
    int** adj = malloc((n + 1) * sizeof(int*));
    int* adj_size = calloc(n + 1, sizeof(int));

    for (int i = 0; i < cities_rows; i++) {
        int u = cities[i][0], v = cities[i][1];
        adj_size[u]++; adj_size[v]++;
    }

    for (int i = 1; i <= n; i++) {
        adj[i] = malloc(adj_size[i] * sizeof(int));
        adj_size[i] = 0;
    }
    for (int i = 0; i < cities_rows; i++) {
        int u = cities[i][0], v = cities[i][1];
        adj[u][adj_size[u]++] = v;
        adj[v][adj_size[v]++] = u;
    }

    long cost = 0;
    int* queue = malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int front = 0, rear = 0;
            visited[i] = 1;
            queue[rear++] = i;
            int nodes = 0;

            while (front < rear) {
                int u = queue[front++];
                nodes++;
                for (int j = 0; j < adj_size[u]; j++) {
                    int v = adj[u][j];
                    if (!visited[v]) {
                        visited[v] = 1;
                        queue[rear++] = v;
                    }
                }
            }
            cost += c_lib + (long)(nodes - 1) * c_road;
        }
    }

    for (int i = 1; i <= n; i++) free(adj[i]);
    free(adj);
    free(adj_size);
    free(queue);
    free(visited);

    return cost;
}
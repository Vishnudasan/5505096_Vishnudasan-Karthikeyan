int minimumMoves(int grid_count, char** grid, int startX, int startY, int goalX, int goalY) {
    int n = grid_count;
    int visited[n][n];
    memset(visited, -1, sizeof(visited));
    int qx[n * n], qy[n * n];
    int front = 0, rear = 0;
    qx[rear] = startX;
    qy[rear] = startY;
    rear++;
    visited[startX][startY] = 0;
    while (front < rear) {
        int x = qx[front];
        int y = qy[front];
        front++;
        if (x == goalX && y == goalY) {
            return visited[x][y];
        }
        for (int i = x - 1; i >= 0 && grid[i][y] != 'X'; i--) {
            if (visited[i][y] == -1) {
                visited[i][y] = visited[x][y] + 1;
                qx[rear] = i;
                qy[rear] = y;
                rear++;
            }
        }
        for (int i = x + 1; i < n && grid[i][y] != 'X'; i++) {
            if (visited[i][y] == -1) {
                visited[i][y] = visited[x][y] + 1;
                qx[rear] = i;
                qy[rear] = y;
                rear++;
            }
        }
        for (int j = y - 1; j >= 0 && grid[x][j] != 'X'; j--) {
            if (visited[x][j] == -1) {
                visited[x][j] = visited[x][y] + 1;
                qx[rear] = x;
                qy[rear] = j;
                rear++;
            }
        }
        for (int j = y + 1; j < n && grid[x][j] != 'X'; j++) {
            if (visited[x][j] == -1) {
                visited[x][j] = visited[x][y] + 1;
                qx[rear] = x;
                qy[rear] = j;
                rear++;
            }
        }
    }
    return -1;
}
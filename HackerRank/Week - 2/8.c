char* gridChallenge(int grid_count, char** grid) {
    static char yes[] = "YES";
    static char no[] = "NO";
    
    for(int i = 0; i< grid_count; i++){
        int len = strlen(grid[i]);
        for (int j = 0; j<len-1; j++){
            for(int k = j+1; k<len; k++){
                if (grid[i][j] > grid[i][k]){
                    char temp = grid[i][j];
                    grid[i][j] = grid[i][k];
                    grid[i][k] = temp;
                }
            }
        }
    }
    int len = strlen(grid[0]);
    for (int col = 0; col<len; col++){
        for(int row = 0; row<grid_count - 1; row++ ){
            if (grid[row][col] > grid[row+1][col]){
                return no;
            }
        }
    }
    return yes;
}
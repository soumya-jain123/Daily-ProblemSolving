class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(int x, int y, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(x < 0 || x >= n || y < 0 || y >= m){
            return 1;
        }

        if(grid[x][y] == 0){
            return 1;
        }

        if(grid[x][y] == -1)
            return 0;
        
        grid[x][y] = -1;

        int perimeter = 0;
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            perimeter += dfs(nx, ny, grid);
        }

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)
                return dfs(i, j , grid);
            }
        }

        return 0;
    }
};
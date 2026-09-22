class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        visited[x][y] = true;;
        int area = 1;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
                !visited[nx][ny] && grid[nx][ny] == 1){
                    area += dfs(nx, ny, visited, grid);
                }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int area = dfs(i, j, visited, grid);
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};
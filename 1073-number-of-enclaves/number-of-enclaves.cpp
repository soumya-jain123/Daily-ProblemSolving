class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    if(grid[i][j] == 1){
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && grid[nx][ny] == 1){
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1)
                    cnt++;
            }
        }

        return cnt;
    }
};
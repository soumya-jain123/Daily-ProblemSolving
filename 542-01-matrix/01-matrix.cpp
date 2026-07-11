class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j} , 0});
                    vis[i][j] = 1;
                }else{
                    vis[i][j] = 0;
                }
            }
        }

        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[row][col] = steps;

            for(int i = 0; i < 4; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    q.push({{nx, ny}, steps + 1});
                }
            }
        }

        return dist;
    }
};
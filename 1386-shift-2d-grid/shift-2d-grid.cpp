class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> newGrid(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                int idx = i * n + j;

                int nidx = (idx + k) % (m * n);

                int ni = nidx / n;
                int nj = nidx % n;

                newGrid[ni][nj] = grid[i][j];
            }
        }

        return newGrid;
    }
};
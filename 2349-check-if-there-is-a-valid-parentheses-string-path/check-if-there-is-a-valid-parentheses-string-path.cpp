class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if((m + n + 1) % 2 != 0)
            return false;
        
        queue<tuple<int,int,int>> q;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(m + n + 1, false)));

        int start = (grid[0][0] == '(') ? 1 : -1;
        if(start < 0)
            return false;

        q.push({0, 0, start});
        visited[0][0][start] = true;

        int dr[] = {1, 0};
        int dc[] = {0, 1};

        while(!q.empty()){
            auto [r, c, bal] = q.front();
            q.pop();

            if(r == m - 1 && c == n - 1){
                if(bal == 0)
                    return true;
                continue;
            }

            for (int k = 0; k < 2; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= m || nc >= n)
                    continue;

                int newBalance = bal;

                if (grid[nr][nc] == '(')
                    newBalance++;
                else
                    newBalance--;

                // Invalid parentheses prefix
                if (newBalance < 0)
                    continue;

                // Too much balance to ever close
                if (newBalance > m + n)
                    continue;

                if (!visited[nr][nc][newBalance]) {

                    visited[nr][nc][newBalance] = true;

                    q.push({nr, nc, newBalance});
                }
            }
        }

        return false;
    }
};
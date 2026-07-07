class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        int mins = 0;//minutes ellpased
        int total = 0;//count total no .of oranges
        int cnt = 0;//count rottens

        queue<pair<int, int>> rotten;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0)
                    total++;
                
                if(grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while(!rotten.empty()){
            int k = rotten.size();

            cnt += k;

            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;

                rotten.pop();

                for(int i =0; i < 4; i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if(newX < 0 || newY < 0 || newX >= m || newY >= n || grid[newX][newY] != 1)
                        continue;
                    
                    grid[newX][newY] = 2;
                    rotten.push({newX, newY});
                }
            }

            if(!rotten.empty())
                mins++;
        }

        return (total == cnt) ? mins : -1;
    }
};
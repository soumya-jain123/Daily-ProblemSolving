class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == (n - 1) && y == (m - 1))
                return diff;
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    int newE = max(abs(heights[x][y] - heights[nx][ny]), diff);

                    if(newE < dist[nx][ny]){
                        dist[nx][ny] = newE;
                        pq.push({newE, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};
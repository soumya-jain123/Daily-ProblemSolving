class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n);

        vector<bool> visited(n, false);

        for(auto edge : roads){
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int dist = edge[2];

            adjList[u].push_back({v, dist});
            adjList[v].push_back({u, dist});
        }
        
        int minScore = INT_MAX;
        function<void(int)> dfs = [&](int curr){
            for(auto [neighbour, weight] : adjList[curr]){
                minScore = min(minScore, weight);

                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    dfs(neighbour);
                }
            }
        };

        visited[0] = true;
        dfs(0);

        return minScore;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adjL;
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adjL[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, pair<int,int>>> q;

        q.push({0, {src, 0}});
        dist[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if(stops > k)
                continue;

            for(auto it : adjL[node]){
                int neigh = it.first;
                int W = it.second;

                if(cost + W < dist[neigh] && stops <= k){
                    dist[neigh] = cost + W;
                    q.push({stops+1, {neigh, dist[neigh]}});
                }
            }
        }
        if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjL;
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adjL[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[0] = -1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node])
                continue;
            
            for(auto it : adjL[node]){
                int v = it.first;
                int wt = it.second;

                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
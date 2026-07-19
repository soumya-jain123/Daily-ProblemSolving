class Solution {
public:
    const int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adjL;
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int d = it[2];

            adjL[u].push_back({v, d});
            adjL[v].push_back({u, d});
        }

        vector<long long> minDist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long, int>>> pq;
        minDist[0] = 0;
        pq.push({0, 0});
        ways[0] = 1;

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > minDist[node])
                continue;

            for(auto it : adjL[node]){
                int v = it.first;
                int w = it.second;

                if(d + w < minDist[v]){
                    minDist[v] = d + w;
                    pq.push({minDist[v], v});
                    ways[v] = ways[node];
                }
                else if(d + w == minDist[v]){
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
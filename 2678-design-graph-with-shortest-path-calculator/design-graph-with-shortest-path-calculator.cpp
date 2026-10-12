class Graph {
public:
    vector<vector<pair<int, int>>> adjL;
    Graph(int n, vector<vector<int>>& edges) {
        adjL.resize(n);

        for(auto &e : edges){
            adjL[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adjL[u].push_back({v, w});
    }
    
    int shortestPath(int node1, int node2) {
        int n = adjL.size();

        vector<int> dist(n, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

        dist[node1] = 0;

        pq.push({0, node1});

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;
            if(u == node2) return d;

            for(auto &edge : adjL[u]){
                int v = edge.first;
                int wt = edge.second;

                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
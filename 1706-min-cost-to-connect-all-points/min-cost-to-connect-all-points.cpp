class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        vector<int> key(n, INT_MAX);
        vector<bool> mst(n, false);

        key[0] = 0;

        for(int i = 0; i < n; i++){
            int u = -1;

            for(int v = 0; v < n; v++){
                if(!mst[v] && (u == -1 || key[v] < key[u])){
                    u = v;
                }
            }

            mst[u] = true;
            ans += key[u];

            for(int v = 0; v < n; v++){
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

                if(dist < key[v])
                    key[v] = dist;
            }
        }

        return ans;
    }
};
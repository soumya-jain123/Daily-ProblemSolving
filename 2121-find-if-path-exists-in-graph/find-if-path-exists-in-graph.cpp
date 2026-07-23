class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visi(n , false);
        queue<int> q;
        unordered_map<int, vector<int>> adjL;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        q.push(source);
        visi[source] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == destination){
                return true;
            }

            for(int v : adjL[u]){
                if(!visi[v]){
                    q.push(v);
                    visi[v] = true;
                }
            }
        }
        return false;
    }
};
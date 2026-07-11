class Solution {
public:

    bool dfs(int node, unordered_map<int , bool> &visited, unordered_map<int , bool> &dfsCalls, unordered_map<int, vector<int>> &adjL){
        visited[node] = true;
        dfsCalls[node] = true;

        for(auto neighbour : adjL[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour, visited, dfsCalls, adjL))
                    return true;
            }else if(dfsCalls[neighbour])
                return true;
        }

        dfsCalls[node] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjL;
        unordered_map<int , bool> visited;
        unordered_map<int, bool> dfsCalls;

        for(auto e : edges){
            int u = e[0];
            int v = e[1];

            adjL[u].push_back(v);
        }

        for(int i = 0; i < V; i++){
            if(!visited[i])
                if(dfs(i, visited, dfsCalls, adjL))
                    return false;
        }

        return true;
    }
};
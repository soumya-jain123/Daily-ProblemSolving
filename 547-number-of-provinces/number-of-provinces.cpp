class Solution {
public:
    void bfs(int src, vector<bool>& visited, vector<vector<int>>& mat){
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(int i = 0; i < mat.size(); i++){
                if(mat[front][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n, false);

        int count = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                bfs(i, visited, isConnected);
            }
        }

        return count;
    }
};
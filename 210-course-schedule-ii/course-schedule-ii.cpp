class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjL;
        for(auto e : prerequisites){
            int u = e[1];
            int v = e[0];

            adjL[u].push_back(v);
        }

        vector<int> indegree(numCourses);
        vector<int> ans;
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            for(auto x : adjL[i])
                indegree[x]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cnt++;

            ans.push_back(front);

            for(auto x : adjL[front]){
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }

        if(cnt == numCourses)
            return ans;
        return {};
    }
};
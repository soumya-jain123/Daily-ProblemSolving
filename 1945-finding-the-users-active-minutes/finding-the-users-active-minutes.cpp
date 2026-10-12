class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> uamFreq;
        vector<int> count(k, 0);

        for(auto &it : logs){
            int id = it[0];
            int time = it[1];

            uamFreq[id].insert(time);
        }

        for(auto &it : uamFreq){
            int uam = it.second.size();
            count[uam - 1]++;
        }

        return count;
    }
};
class Solution {
public:
    int solve(int i, int m, int n, vector<pair<int, int>>& cnt, vector<vector<vector<int>>>& dp){
        if(i == cnt.size()){
            return 0;
        }

        if(dp[i][m][n] != -1)
            return dp[i][m][n];

        int notTake = solve(i + 1, m, n, cnt, dp);

        int take = 0;
        if(cnt[i].first <= m && cnt[i].second <= n)
            take = 1 + solve(i + 1, m - cnt[i].first, n - cnt[i].second, cnt, dp);

        return dp[i][m][n] = max(take, notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<pair<int, int>> cnt;
        for(string s : strs){
            int zero = 0, one = 0;
            for(char c : s){
                if(c == '0')
                    zero++;
                else
                    one++;
            }
            cnt.push_back({zero, one});
        }

        vector<vector<vector<int>>> dp(size, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return solve(0, m, n, cnt, dp);

    }
};
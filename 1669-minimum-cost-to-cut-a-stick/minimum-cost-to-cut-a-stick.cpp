class Solution {
public:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
        if(i > j) return 0;

        int ans = INT_MAX;

        if(dp[i][j] != -1)
            return dp[i][j];

        for(int idx = i; idx <= j; idx++){
            int curr = arr[j + 1] - arr[i - 1] + solve(i, idx - 1, arr, dp) + solve(idx + 1, j, arr, dp);

            ans = min(ans, curr);
        }

        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        int size = cuts.size();

        vector<vector<int>> dp(size + 1, vector<int>(size + 1, -1));
        return solve(1, size - 2, cuts, dp);
    }
};
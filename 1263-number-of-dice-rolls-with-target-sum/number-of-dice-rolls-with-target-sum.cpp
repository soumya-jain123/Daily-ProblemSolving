class Solution {
public:
    const int mod = 1e9 + 7;
    int solve(int n, int k, int t, vector<vector<int>>& dp){
        if(n == 0){
            return (t == 0) ? 1 : 0;
        }
        if(t < n || t > n * k){
            return 0;
        }

        if(dp[n][t] != -1)
            return dp[n][t];
        
        int ways = 0;

        for(int face = 1; face <= k; face++){
            ways = (ways + solve(n - 1, k, t - face, dp)) % mod;
        }

        return dp[n][t] = ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};
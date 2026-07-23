class Solution {
public:
    int solve(int n, int amnt, vector<int>& coins, vector<vector<int>>& dp){
        if(n < 0)
            return 0;
        
        if(amnt == 0)
            return 1;

        if(dp[n][amnt] != -1)
            return dp[n][amnt];
        
        int ex = solve(n - 1, amnt, coins, dp);

        int in = 0;
        if(coins[n] <= amnt){
            in = solve(n, amnt - coins[n], coins, dp);
        }

        return dp[n][amnt] = in + ex;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};
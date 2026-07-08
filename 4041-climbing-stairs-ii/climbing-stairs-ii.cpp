class Solution {
public:
    int solve(int i, vector<long long> &dp, vector<int>& costs){
        if(i == 0)
            return 0;
        if(dp[i] != -1)
            return dp[i];

        long long ans = LLONG_MAX;

        if(i - 1 >= 0){
            ans = min(ans, solve(i - 1, dp, costs) + costs[i-1] + 1ll);
        }
        if(i - 2 >= 0){
            ans = min(ans, solve(i - 2, dp, costs) + costs[i-1] + 4ll);
        }
        if(i - 3 >= 0){
            ans = min(ans, solve(i - 3, dp, costs) + costs[i-1] + 9ll);
        }

        return dp[i] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        // int n = costs.size();
        vector<long long> dp(n + 2, -1);
        return solve(n, dp, costs);
    }
};
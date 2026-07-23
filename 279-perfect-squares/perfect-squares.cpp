class Solution {
public:
    int solve(int i, int n, vector<int>& arr, vector<vector<int>>& dp){
        if(i == 0)
            return n;
        if(n == 0)
            return 0;

        if(dp[i][n] != -1)
            return dp[i][n];
        
        int notTake = solve(i  - 1, n, arr, dp);
        int take = INT_MAX;
        if(arr[i] <= n){
            take = 1 + solve(i, n - arr[i], arr, dp);
        }

        return dp[i][n] = min(take, notTake);
    }
    int numSquares(int n) {
        vector<int> sq;
        for(int i = 1; i * i <= n; i++){
            sq.push_back(i * i);
        }

        int m = sq.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(sq.size() - 1, n, sq, dp);
    }
};
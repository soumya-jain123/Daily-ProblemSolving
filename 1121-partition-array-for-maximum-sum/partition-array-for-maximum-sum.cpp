class Solution {
public:
    int solve(int i, int k, vector<int>& arr, vector<int>& dp){
        int n = arr.size();

        if(i == n){
            return 0;
        }

        if(dp[i] != -1)
            return dp[i];

        int len = 0;
        int maxNum = 0;
        int ans = 0;

        for(int j = i; j < min(n, i + k); j++){
            len++;

            maxNum = max(maxNum, arr[j]);

            int sum = maxNum * len + solve(j + 1, k, arr, dp);

            ans = max(ans, sum);
        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        vector<int> dp(arr.size(), -1);
        return solve(0, k, arr, dp);
    }
};
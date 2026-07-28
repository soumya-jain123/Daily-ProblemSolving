class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int total = INT_MIN;

        for(int idx = i; idx <= j; idx++){
            int curr = nums[i - 1] * nums[idx] * nums[j + 1];

            int remaining = solve(i, idx - 1, nums, dp) + solve(idx + 1, j, nums, dp);

            total = max(total, curr + remaining);
        }

        return dp[i][j] = total;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return solve(1, n, nums, dp);
    }
};
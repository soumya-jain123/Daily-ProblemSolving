class Solution {
public:
    bool solve(int n, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(sum == 0)
            return true;
        
        if(n == 0)
            return false;

        if(dp[n - 1][sum] != -1)
            return dp[n - 1][sum];
        
        if(nums[n - 1] > sum)
            return solve(n - 1, sum, nums, dp);
        
        return dp[n- 1][sum] = solve(n - 1, sum - nums[n - 1], nums, dp) || solve(n - 1, sum, nums, dp);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0)
            return false;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        return solve(n, sum / 2, nums, dp);
    }
};
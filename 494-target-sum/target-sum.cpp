class Solution {
public:
    int solve(int i, int curr, int find, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(i == n)
            return curr == find;
        
        if(dp[i][curr] != -1)
            return dp[i][curr];
        
        int ex = solve(i + 1, curr, find, nums, dp);

        int in = 0;
        if(curr + nums[i] <= find)
            in = solve(i + 1, curr + nums[i], find, nums, dp);
        
        return dp[i][curr] = ex + in;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = 0;
        for(int x : nums){
            total += x;
        }

        int find = (total + target) / 2;

        if(total < abs(target))
            return 0;

        if((total + target) % 2)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int>(find + 1, -1));
        
        return solve(0, 0, find, nums, dp);
    }
};
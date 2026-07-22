class Solution {
public:
    int solve(int i, int curr, int total, int target,
              vector<int>& stones,
              vector<vector<int>>& dp) {

        if (i == stones.size())
            return abs((total - curr) - curr);

        if (dp[i][curr] != -1)
            return dp[i][curr];

        int notTake = solve(i + 1, curr, total, target, stones, dp);

        int take = INT_MAX;
        if (curr + stones[i] <= target)
            take = solve(i + 1, curr + stones[i], total, target, stones, dp);

        return dp[i][curr] = min(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {

        int total = accumulate(stones.begin(), stones.end(), 0);
        int target = total / 2;
        int n = stones.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(0, 0, total, target, stones, dp);
    }
};
class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long solve(int i, int j, vector<vector<long long>>& dp) {

        // We want to choose 0 elements
        if (j == 0)
            return 1;

        // Not enough elements available
        if (i == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Don't take current element
        long long notTake = solve(i - 1, j, dp);

        // Take current element
        long long take = solve(i - 1, j - 1, dp);

        return dp[i][j] = (take + notTake) % MOD;
    }

    int minMaxSums(vector<int>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        // dp[i][j] = number of ways to choose exactly j
        // elements from first i elements
        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(k + 1, -1)
        );

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // nums[i] is the MINIMUM
            // Choose 0 to k-1 elements after nums[i]
            for (int j = 0; j <= k - 1; j++) {

                int remaining = n - i - 1;

                if (j <= remaining) {
                    long long ways = solve(remaining, j, dp);

                    ans = (ans + (long long)nums[i] * ways) % MOD;
                }
            }

            // nums[i] is the MAXIMUM
            // Choose 0 to k-1 elements before nums[i]
            for (int j = 0; j <= k - 1; j++) {

                if (j <= i) {
                    long long ways = solve(i, j, dp);

                    ans = (ans + (long long)nums[i] * ways) % MOD;
                }
            }
        }

        return ans;
    }
};
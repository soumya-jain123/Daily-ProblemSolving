class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxDp(n);
        vector<int> minDp(n);

        maxDp[0] = nums[0];
        minDp[0] = nums[0];

        int ans = nums[0];

        for(int i = 1; i < n; i++){
            maxDp[i] = max({nums[i], nums[i] * maxDp[i - 1], nums[i] * minDp[i - 1]});
            minDp[i] = min({nums[i], nums[i] * minDp[i - 1], nums[i] * maxDp[i - 1]});

            ans = max(ans, maxDp[i]);
        }

        return ans;
    }
};
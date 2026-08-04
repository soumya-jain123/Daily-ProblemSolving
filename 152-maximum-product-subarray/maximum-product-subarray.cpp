class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxPro(n);
        vector<int> minPro(n);

        maxPro[0] = nums[0];
        minPro[0] = nums[0];

        int ans = nums[0];

        for(int i = 1; i < n; i++){
            maxPro[i] = max({nums[i], nums[i] * maxPro[i - 1], nums[i] * minPro[i - 1]});
            minPro[i] = min({nums[i], nums[i] * minPro[i - 1], nums[i] * maxPro[i - 1]});

            ans = max(ans, maxPro[i]);
        }

        return ans;
    }
};
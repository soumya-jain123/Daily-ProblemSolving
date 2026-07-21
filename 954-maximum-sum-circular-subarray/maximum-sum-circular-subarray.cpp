class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;

        int maxSum = 0;
        int bestMax = nums[0];

        int minSum = 0;
        int bestMin = nums[0];

        for(int i = 0; i < nums.size(); i++){
            maxSum = max(nums[i], maxSum + nums[i]);
            bestMax = max(bestMax, maxSum);

            minSum = min(nums[i], minSum + nums[i]);
            bestMin = min(bestMin, minSum);

            total += nums[i];
        }

        if(bestMax < 0)
            return bestMax;

        return max(bestMax, total - bestMin);
    }
};
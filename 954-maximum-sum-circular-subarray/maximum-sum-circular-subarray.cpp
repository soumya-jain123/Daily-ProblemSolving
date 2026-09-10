class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;

        int currMax= 0;
        int bestM = nums[0];

        int currMin = 0;
        int bestMi = nums[0];

        for(int i = 0; i < nums.size(); i++){
            currMax = max(nums[i], currMax + nums[i]);
            bestM = max(bestM, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            bestMi = min(bestMi, currMin);

            total += nums[i];
        }

        if(bestM < 0)
            return bestM;
        else
            return max(bestM, total - bestMi);

    }
};
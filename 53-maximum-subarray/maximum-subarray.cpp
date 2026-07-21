class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];

        int end = nums[0];

        for(int i = 1; i < nums.size(); i++){
            end = max(nums[i], end + nums[i]);

            result = max(result, end);
        }

        return result;
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> unq;

        int left = 0, ans = 0, sum = 0;

        for(int rght = 0; rght < nums.size(); rght++){
            while(unq.count(nums[rght])){
                unq.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            unq.insert(nums[rght]);
            sum += nums[rght];

            ans = max(ans, sum);
        }

        return ans;
    }
};
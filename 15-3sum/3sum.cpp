class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       vector<vector<int>> ans;

       int n = nums.size();

       for(int fix = 0 ; fix < n; fix++){
            if(fix > 0 && nums[fix] == nums[fix - 1]) continue;
            int left = fix + 1;
            int right = n - 1;

            while(left < right){
                int sum = nums[fix] + nums[left] + nums[right];
                if(sum == 0){
                    ans.push_back({nums[fix], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right &&nums[left] == nums[left - 1]){
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                else if(sum > 0){
                    right--;
                }else{
                    left++;
                }
            }
       }
       return ans;
    }
};
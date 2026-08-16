class Solution {
public:
    int atMost(int k, vector<int>& arr){
        unordered_map<int, int> freq;
        int left = 0;
        int count = 0;
        int distinct = 0;

        for(int right = 0; right < arr.size(); right++){
            freq[arr[right]]++;

            if(freq[arr[right]] == 1)
                distinct++;
            
            while(distinct > k){
                freq[arr[left]]--;

                if(freq[arr[left]] == 0)
                    distinct--;
                
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(k, nums) - atMost(k - 1, nums);
    }
};
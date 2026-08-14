class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq; // current no. of 1 i have seen so far
        freq[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int x : nums){
            sum += x;

            if(freq.find(sum - goal) != freq.end()){
                ans += freq[sum - goal];
            }

            freq[sum]++;
        }

        return ans;


    }
};
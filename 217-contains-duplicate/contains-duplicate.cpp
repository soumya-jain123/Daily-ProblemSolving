class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int x : nums){
            if(freq.find(x) != freq.end()){
                return true;
            }
            freq[x]++;
        }

        return false;
    }
};
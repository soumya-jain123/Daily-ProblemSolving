class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> present(101, false);

        int mn = INT_MAX, mx = INT_MIN;

        for (int x : nums) {
            present[x] = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }

        vector<int> ans;

        for(int i = mn; i <= mx; i++){
            if(present[i] == false)
                ans.push_back(i);
        }

        return ans;
    }
};
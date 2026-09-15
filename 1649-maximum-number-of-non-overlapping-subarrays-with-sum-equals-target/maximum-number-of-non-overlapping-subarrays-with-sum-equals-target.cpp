class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> st;
        int ans = 0;
        int prefix = 0;

        st.insert(0);

        for(int num : nums){
            prefix += num;
            if(st.count(prefix - target)){
                ans++;

                st.clear();
                st.insert(0);
                prefix = 0;
            }else{
                st.insert(prefix);
            }
        }

        return ans;
    }
};
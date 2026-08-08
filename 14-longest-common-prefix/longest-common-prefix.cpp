class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs[0];

        string last = strs[strs.size() - 1];

        int minimum = min(first.size(), last.size());

        string ans = "";

        // int count = 0;

        for(int i = 0; i < minimum; i++){
            if(first[i] != last[i]){
                break;
            }
            ans += first[i];
        }

        return ans;
    }
};
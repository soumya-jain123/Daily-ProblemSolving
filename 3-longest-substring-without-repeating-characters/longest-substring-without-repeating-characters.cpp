class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        if(n == 0)
            return 0;

        vector<bool> visited(256, false);

        int start = 0, end = 0;

        int ans = INT_MIN;

        while(end < n){
            while(visited[s[end]] == true){
                visited[s[start]] = false;
                start++;
            }

            visited[s[end]] = true;
            ans = max(ans, end - start + 1);
            end++;
        }

        return ans;
    }
};
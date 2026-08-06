class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int strt = 0;
        int maxLen = 1;

        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j]){
                    if(j - i <= 2)
                        dp[i][j] = true;
                    else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if(dp[i][j] && j - i + 1> maxLen){
                    maxLen = j - i + 1;
                    strt = i;
                }
            }
        }

        return s.substr(strt, maxLen);
    }
};
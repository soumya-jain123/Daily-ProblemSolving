class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(i == 0 || j == 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i - 1] == t[j - 1])
            return dp[i][j] = 1 + solve(i - 1, j - 1, s, t, dp);
        
        else
            return dp[i][j] = max(solve(i - 1, j, s ,t,dp), solve(i, j - 1, s, t, dp));
    }
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.length();
        int m = n;
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, s, rev, dp);
    }
};
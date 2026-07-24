class Solution {
public:

    int solve(int i, int j, string& t, string& u, vector<vector<int>>& dp){
        if(i == 0) return 0;
        if(j == 0) return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(t[i - 1] == u[j - 1])
            return dp[i][j] = 1 + solve(i - 1, j - 1, t, u, dp);
        else{
            return dp[i][j] = max(solve(i, j - 1, t, u, dp), solve(i - 1, j, t, u, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i =  text1.length();
        int j = text2.length();

        vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
        return solve(i, j, text1, text2, dp);
    }
};
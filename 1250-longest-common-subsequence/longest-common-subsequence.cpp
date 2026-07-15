class Solution {
public:
    // int solve(string& txt1, string &txt2, int i, int j){
    //     if(i == txt1.length()) return 0;
    //     if(j == txt2.length()) return 0;

    //     int ans = 0;
    //     if(txt1[i] == txt2[j])
    //         ans = 1 + solve(txt1, txt2, i + 1, j + 1);
    //     else{
    //         ans = max(solve(txt1, txt2, i + 1, j), solve(txt1, txt2, i, j + 1));
    //     }

    //     return ans;
    // }

    int solve(string &t1, string &t2, int i, int j, vector<vector<int>>& dp){
        if(i == 0) return 0;
        if(j == 0) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(t1[i - 1] == t2[j - 1])
            ans = 1 + solve(t1, t2, i - 1, j - 1, dp);
        else{
            ans = max(solve(t1, t2, i - 1, j, dp), solve(t1, t2, i, j - 1, dp));
        }

        dp[i][j] = ans;
        return dp[i][j];

    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(text1, text2, m, n, dp);
    }
};
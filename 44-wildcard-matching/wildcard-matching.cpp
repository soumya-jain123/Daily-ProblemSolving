class Solution {
public:
    bool isbool(string& p, int len){
        for(int i = 0; i <= len; i++)
            if(p[i] != '*')
                return false;
        
        return true;
    }
    bool solve(int i, int j, string& t, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0)
            return true;
        
        if(j < 0 && i >= 0)
            return false;
        
        if(i < 0 && j >= 0)
            return isbool(p, j);
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(t[i] == p[j] || p[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, t, p, dp);
        
        if(p[j] == '*')
            return dp[i][j] = solve(i - 1, j, t, p, dp) || solve(i, j - 1, t, p, dp);
            
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solve(n - 1, m - 1, s, p, dp);
    }
};
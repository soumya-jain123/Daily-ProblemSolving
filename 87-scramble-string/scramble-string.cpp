class Solution {
public:
    unordered_map<string, bool> dp;
    bool solve(string a, string b){
        if(a == b)
            return true;
        
        if(a.length() != b.length())
            return false;

        string key = a + " " + b;

        if(dp.find(key) != dp.end())
            return dp[key];
        
        int n = a.length();

        if(n == 1)
            return a == b;
        
        for(int k = 1; k < n; k++){
            // no swap
            if(solve(a.substr(0, k), b.substr(0, k)) && solve(a.substr(k), b.substr(k)))
                return dp[key] = true;
            
            if(solve(a.substr(0, k), b.substr(n - k)) && solve(a.substr(k), b.substr(0, n - k)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};
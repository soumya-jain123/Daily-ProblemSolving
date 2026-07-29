class Solution {
public:

    bool isPalin(int i, int j, string& s){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    int solve(int i, string& s, vector<int>& dp){
        int n = s.size();

        if(i == n || isPalin(i, n - 1, s))
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        int ansF = INT_MAX;

        for(int k = i; k < n; k++){
            if(isPalin(i, k, s)){
                int cuts = 1 + solve(k + 1, s, dp);
                ansF = min(ansF, cuts);
            }
        }

        return dp[i] = ansF;
    }
    int minCut(string s) {
        int n = s.length();

        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};
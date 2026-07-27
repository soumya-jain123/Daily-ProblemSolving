class Solution {
public:

    bool isPredecessor(string& small, string& large){
        if(large.size() != small.size() + 1)
            return false;
        
        int i = 0, j= 0;

        while(i < small.size() && j < large.size()){
            if(small[i] == large[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }

        return i == small.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        int n = words.size();

        vector<int> dp(n, 1);

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPredecessor(words[j], words[i]) && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }

            if(dp[i] > ans)
                ans = dp[i];
        }

        return ans;
    }
};
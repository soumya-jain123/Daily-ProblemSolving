class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long> dp(n, 1);
        vector<int> idx(k, 0);

        for(int i = 1; i < n; i++){
            long long nextNum = LLONG_MAX;

            for(int j = 0; j < k; j++){
                nextNum = min(
                    nextNum,
                    dp[idx[j]] * primes[j]
                );
            }

            dp[i] = nextNum;

            for(int j = 0; j < k; j++){
                if(dp[idx[j]] * primes[j] == nextNum){
                    idx[j]++;
                }
            }
        }

        return (int)dp[n - 1];
    }
};
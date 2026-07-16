class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int mx = INT_MIN;
        vector<int> prefixGCD;

        for(int x : nums){
            mx = max(mx, x);
            prefixGCD.push_back(gcd(mx, x));
        }

        sort(prefixGCD.begin(), prefixGCD.end());

        long long ans = 0;
        int i = 0, j = n - 1;
        while(i < j){
            ans += gcd(prefixGCD[i], prefixGCD[j]);
            i++;
            j--;
        }

        return ans;
    }
};
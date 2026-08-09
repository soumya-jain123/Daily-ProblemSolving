class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> freq(1 << 10, 0);

        long long ans = 0;
        int mask = 0;

        freq[0] = 1;

        for(char ch : word){
            mask ^= (1 << (ch - 'a'));

            ans += freq[mask]; // ssaare char even freq hai;

            for(int j = 0; j < 10; j++){ // jb exactly ek char odd frequency ka hoga
                int newMask = mask ^ (1 << j);
                ans+= freq[newMask];
            }

            freq[mask]++;
        }

        return ans;
    }
};
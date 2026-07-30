class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();

        int groupIncrement = 1;

        int ans = 0;

        int totalGroups = n / 8;

        for(int i = 0; i < totalGroups; i++){
            ans += groupIncrement * 8;

            groupIncrement++;
        }

        int remaining = n % 8;
        ans += groupIncrement * remaining;

        return ans;
    }
};
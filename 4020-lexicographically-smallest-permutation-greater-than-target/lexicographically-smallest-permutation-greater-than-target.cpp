class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // We will try to make the answer greater at position i.
        // Start from the RIGHT so that the changed position
        // is as far right as possible.
        for (int i = n - 1; i >= 0; i--) {

            // We need target[0 ... i-1] to be exactly the same.
            vector<int> cnt = freq;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int c = target[j] - 'a';

                if (cnt[c] == 0) {
                    possible = false;
                    break;
                }

                cnt[c]--;
            }

            if (!possible)
                continue;

            // At position i, choose the smallest character
            // that is strictly greater than target[i].
            int current = target[i] - 'a';

            for (int c = current + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    string ans = target.substr(0, i);

                    // Make the string strictly greater here
                    ans += char('a' + c);
                    cnt[c]--;

                    // Put all remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        while (cnt[k] > 0) {
                            ans += char('a' + k);
                            cnt[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        int left = 0;
        int formed = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(char c : t){
            need[c]++;
        }

        for (int right = 0; right < s.length(); right++){
            char c = s[right];
            window[c]++;

            if(need.count(c) && window[c] <= need[c])
                formed++;

            while(formed == t.length()){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                char leftchar = s[left];

                window[leftchar]--;

                if(need.count(leftchar) && window[leftchar] < need[leftchar])
                    formed--;

                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";
        return s.substr(start, minLen);
    }
};
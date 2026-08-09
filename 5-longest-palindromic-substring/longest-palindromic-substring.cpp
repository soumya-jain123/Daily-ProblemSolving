class Solution {
public:
    void solve(string &s, int begin, int end, int &start, int &maxLen){
        if(begin < 0 || end >= s.length() || s[begin] != s[end])
            return;

        if(end - begin + 1 > maxLen){
            start = begin;
            maxLen = end - begin + 1;
        }

        solve(s, begin - 1, end + 1, start, maxLen);
    }
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < s.length(); i++){
            solve(s, i, i, start, maxLen);

            solve(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};
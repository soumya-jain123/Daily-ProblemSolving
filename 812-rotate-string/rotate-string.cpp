class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string bigStr = s + s;

        return bigStr.find(goal) != string::npos;
    }
};
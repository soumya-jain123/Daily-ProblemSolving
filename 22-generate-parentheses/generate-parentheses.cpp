class Solution {
public:
    void backtracking(string curr, int start, int close, int n, vector<string>& res){
        if(curr.length() == 2*n){
            res.push_back(curr);
            return;
        }

        if(start < n){
            backtracking(curr + '(', start + 1, close, n, res);
        }

        if(close < start)
            backtracking(curr + ')', start, close + 1, n, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtracking("", 0, 0, n, res);
        return res;
    }
};
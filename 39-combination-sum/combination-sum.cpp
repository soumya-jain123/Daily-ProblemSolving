class Solution {
public:
    void solve(int idx, vector<int>& curr, vector<vector<int>> &ans, int target, vector<int> &arr){
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }
        
        if(arr[idx] <= target){
            curr.push_back(arr[idx]);
            solve(idx, curr, ans, target - arr[idx], arr);
            curr.pop_back();
        }

        solve(idx + 1, curr, ans, target, arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, target, candidates);

        return ans;
    }
};
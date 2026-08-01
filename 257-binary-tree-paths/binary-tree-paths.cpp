class Solution {
public:
    void solve(TreeNode* root, string& temp, vector<string>& ans) {
        if (!root)
            return;

        int len = temp.size();

        temp += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(temp);
        } else {
            temp += "->";
            solve(root->left, temp, ans);
            solve(root->right, temp, ans);
        }

        temp.resize(len);   // Backtrack
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp;
        solve(root, temp, ans);
        return ans;
    }
};
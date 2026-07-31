/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* leftSub, TreeNode* rightSub){
        if(!leftSub && !rightSub)
            return true;
        if(!leftSub || !rightSub || leftSub->val != rightSub->val)
            return false;
        
        return (solve(leftSub->left, rightSub->right) &&
            solve(leftSub->right, rightSub->left));
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right);
    }
};
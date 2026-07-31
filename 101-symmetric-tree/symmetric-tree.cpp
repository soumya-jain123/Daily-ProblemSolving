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
    // bool solve(TreeNode* leftSub, TreeNode* rightSub){
    //     if(!leftSub && !rightSub)
    //         return true;
    //     if(!leftSub || !rightSub || leftSub->val != rightSub->val)
    //         return false;
        
    //     return (solve(leftSub->left, rightSub->right) &&
    //         solve(leftSub->right, rightSub->left));
    // }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode* n1 = q.front();
            q.pop();

            TreeNode* n2 = q.front();
            q.pop();

            if(!n1 && !n2)
                continue;
            
            if(!n1 || !n2 || n1->val != n2->val)
                return false;
            
            q.push(n1->left);
            q.push(n2->right);
            q.push(n1->right);
            q.push(n2->left);

        }
        return q.empty();
    }
};
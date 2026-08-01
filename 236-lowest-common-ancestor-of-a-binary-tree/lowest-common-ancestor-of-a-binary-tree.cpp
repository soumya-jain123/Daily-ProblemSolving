/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return nullptr;

        if(root->val == p->val || root->val == q->val)
            return root;
        
        TreeNode* leftChild = solve(root->left, p, q);
        TreeNode* rightChild = solve(root->right, p, q);

        if(leftChild != nullptr && rightChild != nullptr)   return root;
        else if(leftChild && rightChild == nullptr) return leftChild;
        else if(leftChild == nullptr && rightChild) return rightChild;
        else return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};
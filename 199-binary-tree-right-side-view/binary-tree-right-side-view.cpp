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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* front = q.front().first;
                int hd = q.front().second;
                q.pop();

                if(i == size - 1)
                    ans.push_back(front->val);
                if(front->left)
                    q.push({front->left, hd - 1});
                if(front->right)
                    q.push({front->right, hd + 1});
            }
        }

        return ans;
    }
};
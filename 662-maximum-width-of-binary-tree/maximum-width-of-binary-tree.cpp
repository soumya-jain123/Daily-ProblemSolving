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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*, long long>> q; // node & index of that node
        q.push({root, 0});

        long long ans = INT_MIN;

        while(!q.empty()){
            long long left, right;
            int size = q.size();

            int minIdx = q.front().second; // base index of level

            for(int i = 0; i < size; i++){
                TreeNode* front = q.front().first;
                long long curr = q.front().second;
                q.pop();

                curr = curr - minIdx;

                if(i == 0)
                    left = curr;
                if(i == size - 1)
                    right = curr;
                
                if(front->left)
                    q.push({front->left, 2 * curr + 1});
                if(front->right)
                    q.push({front->right, 2 * curr + 2});
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
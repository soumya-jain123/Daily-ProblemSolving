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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes; // hd, level wise nodes
        queue<pair<TreeNode*, pair<int, int>>> q;

        vector<vector<int>> ans;

        if(!root)
            return ans;

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto front = q.front().first;
            auto hd = q.front().second.first;
            auto lvl = q.front().second.second;
            q.pop();

            nodes[hd][lvl].push_back(front->val);

            if(front->left)
                q.push({front->left, {hd - 1, lvl + 1}});
            if(front->right)
                q.push({front->right, {hd + 1, lvl + 1}});
        }

        for(auto i : nodes){
            vector<int> temp;
            for(auto j : i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k : j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
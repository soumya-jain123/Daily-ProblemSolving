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
    TreeNode* mapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& map, int t){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = nullptr;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->val == t)
                res = front;

            if(front->left){
                map[front->left] = front;
                q.push(front->left);
            }

            if(front->right){
                map[front->right] = front;
                q.push(front->right);
            }
        }

        return res;
    }
    int solve(unordered_map<TreeNode*, TreeNode*>& map, TreeNode* st){
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visit;

        q.push(st);
        visit[st] = true;

        int ans = 0;

        while(!q.empty()){
            int sz = q.size();
            bool flag = false;

            for(int i = 0; i < sz; i++){
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !visit[front->left]){
                    visit[front->left] = true;
                    flag = true;
                    q.push(front->left);
                }

                if(front->right && !visit[front->right]){
                    visit[front->right] = true;
                    flag = true;
                    q.push(front->right);
                }

                if(map[front] && !visit[map[front]]){
                    visit[map[front]] = true;
                    flag =  true;
                    q.push(map[front]);
                }
            }

            if(flag) ans += 1;
        }

        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root)
            return 0;

        unordered_map<TreeNode*, TreeNode*> map;
        TreeNode* pntr = mapping(root, map, start);

        return solve(map, pntr);
    }
};
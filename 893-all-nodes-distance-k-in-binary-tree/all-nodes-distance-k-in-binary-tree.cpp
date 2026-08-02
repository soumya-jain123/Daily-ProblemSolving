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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};

        unordered_map<TreeNode*, TreeNode*> map;
        mapping(root, map);

        return dist(target, map, k);
    }

    void mapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& map){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->left){
                map[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                map[front->right] = front;
                q.push(front->right);
            }
        }
    }

    vector<int> dist(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parentMap, int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited; 

        q.push(target);
        visited.insert(target);

        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();

            if (currentLevel++ == k) break;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if (parentMap.count(node) && visited.find(parentMap[node]) == visited.end()) {
                    visited.insert(parentMap[node]);
                    q.push(parentMap[node]);
                }
            }
        }

        // All nodes in queue are now at distance K from the target
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
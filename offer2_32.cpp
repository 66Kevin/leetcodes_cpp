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
    vector<int> levelOrder(TreeNode* root) {
        if(root == nullptr) return {}; // C++11特性，返回一个空的vector<int>对象

        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* now = q.front();
            res.push_back(now -> val);
            q.pop();
            
            if(now -> left != nullptr) {
                q.push(now -> left);
            }
            if(now -> right != nullptr) {
                q.push(now -> right);
            }
        }

        return res;
    }
};

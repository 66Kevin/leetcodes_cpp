//
// Created by 王月艺 on 2022/2/1.
//

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        if(root == nullptr){
            return ret;
        }

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int levelNodeNums = que.size();
            ret.push_back(vector<int> ());
            for(int i=0; i<levelNodeNums; ++i){
                TreeNode* frontNode = que.front();
                que.pop();
                ret.back().push_back(frontNode->val);
                if(frontNode->left) que.push(frontNode -> left);
                if(frontNode->right) que.push(frontNode -> right);
            }
        }

        return ret;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);

        while(!que.empty()) {
            /* 计算队列的大小也即有多少个孩子 */
            int size = que.size();
            vector<int> vec;
            /* 层序遍历 */
            for(int i = 0; i < size; i++) {
                /* 获取第一个节点数据 */
                TreeNode* node = que.front();
                que.pop();

                vec.push_back(node->val);
                if(node->left != NULL) que.push(node->left);
                if(node->right != NULL) que.push(node->right);
            }
            /* 将一层的数据保存 */
            result.push_back(vec);
        }
        return result;
    }
};

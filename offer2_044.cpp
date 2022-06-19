class Solution {
public:
    //层次遍历，如何判断哪些节点是属于同一层的是关键（队列实现层序遍历）
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return {}; //返回空的vector C++特性
        }
        vector<int> allMax;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int curMax = INT_MIN;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();
                curMax = max(curMax, node->val);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            allMax.push_back(curMax);
        }
        return allMax;
    }
};

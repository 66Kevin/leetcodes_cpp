class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    
    vector<int> robTree(TreeNode* cur) {
        if (cur == NULL) return vector<int>{0, 0}; // 长度为2的数组，0：不偷，1：偷
        // 先遍历到叶节点
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 处理逻辑
        // 偷cur：当前节点val加上左右节点不偷的值
        int val1 = cur->val + left[0] + right[0];
        // 不偷cur：不偷当前节点，加上左右节点最大的值
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};

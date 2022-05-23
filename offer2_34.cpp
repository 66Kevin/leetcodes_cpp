class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }

    void dfs(TreeNode* root, int targetSum){
        if(root == nullptr) return;
        
        path.push_back(root->val);
        targetSum -= root->val;
        // 注意题目中是从根节点到叶子结点！！！
        if(root->left == nullptr && root->right == nullptr && targetSum==0){
            ret.push_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }
};

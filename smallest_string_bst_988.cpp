class Solution {
public:
    vector<string> path;
    string smallestFromLeaf(TreeNode *root)
    {
        dfs(root, "");
        sort(path.begin(), path.end()); //升序排序

        return path[0];
    }

    void dfs(TreeNode *root, string s)
    {
        if (!root)
            return;
        s += 'a' + root->val;
        if (!root->left && !root->right)
        {
            reverse(s.begin(), s.end()); //题目要求从根节点到叶节点，因此反转
            path.push_back(s);
            return;
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
};

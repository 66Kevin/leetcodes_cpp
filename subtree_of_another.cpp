class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr)
            return true;
        if(root == nullptr || subRoot == nullptr)
            return false;
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot) || judge(root, subRoot);
    }

    bool judge(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr || root2 == nullptr)
            return false;
        if(root1 -> val != root2 -> val)
            return false;     
        return judge(root1 -> left, root2 -> left) && judge(root1 -> right, root2 -> right);
    }
};

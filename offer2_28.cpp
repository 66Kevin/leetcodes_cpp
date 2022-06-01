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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return compare(root->left, root->right);
    }
    bool compare(TreeNode* left, TreeNode* right){
        if(left == NULL && right != NULL) return false;
        else if(left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if(left -> val != right -> val) return false;

        bool outside = compare(left->left, right->right);   // 左子树：左、 右子树：右
        bool inside = compare(left->right, right->left);    // 左子树：右、 右子树：左
        return outside && inside;  
    }
};


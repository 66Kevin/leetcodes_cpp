/*
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return NULL;
        
        // 1、建立根节点，前序遍历中第一个数字得到根节点值preorder[0]
        TreeNode *root = new TreeNode(preorder[0]);
        // 2、根据根节点来划分 前序数组 和 中序数组，找到 中序数组 中根节点的位置
        auto inRoot = find(inorder.begin(), inorder.end(), preorder[0]);
        // 3、根据根节点的位置划分中序数组，中序数组根节点的左侧为左子树，右侧为右子树
        vector<int> inLeft(inorder.begin(), inRoot);
        vector<int> inRight(inRoot+1, inorder.end());
        // 4、划分前序数组，根据中序数组的左右子树的大小
        int inLeftSize = inLeft.size(); //两种遍历数组的长度是一样的
        vector<int> preLeft(preorder.begin()+1, preorder.begin()+1+inLeftSize);
        vector<int> preRight(preorder.begin()+1+inLeftSize, preorder.end());
        
        // 5、递归处理左右子树
        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);
        return root;
    }
};

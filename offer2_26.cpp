class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
     //树 A 为空 或 树 B 为空 时，直接返回 false
     if (A == nullptr || B == nullptr) return false;
    /* 
    1. 判断 B 是 A 的子树，recur(A, B);
    2. 判断 B 是 A 的左子树，isSubisSubStructure(A->left, B);
    3. 判断 B 是 A 的右子树，isSubisSubStructure(A->right, B);
    */
    return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    bool recur(TreeNode* A, TreeNode* B) {
        // 当节点B为空：说明树B已匹配完成
        if (B == nullptr) return true;
        // A遍历完了还没找到B或者A的值与B的值不想等，返回false
        if (A == nullptr || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};


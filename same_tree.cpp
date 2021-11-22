#include <vector>
#include <iostream>
using namespace std;


 //Definition for a binary tree node.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if( p==nullptr && q==nullptr) return true;

        if(p==nullptr || q== nullptr) return false;

        if(p->val == q->val){
            // 注意：只要是两者中的一个返回false，就直接返回false
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }else{
            return false;
        }
    }
};
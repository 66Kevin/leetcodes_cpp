//
// Created by 王月艺 on 2022/1/29.
//
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    // 二叉树的diameter就是所有结点为根的diameter中最大的那个
    // 需要一个值来保存我这个每次比较更新的最大直径值，用self.max = 0来初始化这个值
    // 每次获得一个节点的左子树和右子树的值的时候，都需要比较一下self.max和左子树高度+右子树高度的大小，把更大的保存下来
    // 如何求左子树和右子树的高度呢，那就是经典的递归求高度问题：max(depth(root.left), depth(root.right))+1
public:
    int max_depth=0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return max_depth;
    }
    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = depth(root->left);
        int right = depth(root->right);
        max_depth = max(max_depth, left+right);

        return max(left, right)+1;
    }
};
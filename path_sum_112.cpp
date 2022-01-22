//
// Created by 王月艺 on 2022/1/22.
//
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归思想：
// 1. 定义出最终情况（叶子节点）是否等于sum
// 2. 递归结束条件
class Solution1 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        // 1. 定义出最终情况（叶子节点）是否等于sum
        if (root->left == nullptr && root->right == nullptr) {
            return sum == root->val;
        }
        // 2. 递归结束条件
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

class Solution2{
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == nullptr) return false;
        stack<pair<TreeNode *, int>> __stack;

        __stack.push(make_pair(root, sum));
        while(!__stack.empty()){
            auto item = __stack.top();
            auto node = item.first;
            auto sum = item.second;
            __stack.pop();

            if(node->left == nullptr && node ->right == nullptr && sum == node ->val){
                return true;
            }

            if(node -> left){
                __stack.push(make_pair(node->left, sum - node->val));
            }

            if(node -> right){
                __stack.push(make_pair(node->right, sum - node->val));
            }
        }

        return false;
    }
};

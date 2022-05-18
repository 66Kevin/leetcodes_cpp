/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    // 复盘：错误的创建了dummynode，题目中说不能创建任何新节点。所以head应该是第一个节点
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        dfs(root);
        head->left = pre; // cur==null跳出dfs循环后构建完毕，需要把head(第一个节点)左指针指向尾巴(pre)
        pre->right = head; // 尾巴的右指针指向head
        return head;
    }
private:
    Node *pre, *head; // head记录第一个节点，pre记录cur前一个节点
    void dfs(Node* cur) {
        if(cur == NULL) return;
        dfs(cur->left);
        if(pre != nullptr) pre->right = cur; //pre不为空时，则把pre右指针指向cur
        else head = cur; // pre为空说明正在访问第一个节点，把cur设为head
        cur->left = pre; // cur左指针指向pre
        pre = cur;       // pre右移动
        dfs(cur->right);
    }
};

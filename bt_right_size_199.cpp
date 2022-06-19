class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //每一层的最右侧
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        vector<int> ans;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            vector<int> tmp;
            for(int i = 0; i < size; ++i){
                TreeNode* node = que.front();
                que.pop();
                tmp.push_back(node -> val);
                if(node -> left != nullptr) que.push(node -> left);
                if(node -> right != nullptr) que.push(node -> right);
            }
            ans.push_back(tmp[tmp.size()-1]);
        }
        return ans;
    }
};

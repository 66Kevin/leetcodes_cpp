class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> que;
        que.push(root);
        int ans;

        while(!que.empty()){
            int size = que.size();
            vector<int> tmp;

            for(int i=0; i<size; ++i){
                TreeNode* node = que.front(); que.pop();
                tmp.push_back(node -> val);
                if(node -> left) que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
            ans = tmp[0];
        }
        return ans;
    }
};

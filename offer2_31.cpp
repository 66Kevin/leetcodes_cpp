class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sta; 
        int cur = 0;    // popped序列中的当前的元素
        for (int i = 0; i < pushed.size(); ++ i) { 
            sta.push(pushed[i]);
            while (!sta.empty() && sta.top() == popped[cur]) { 
                sta.pop();
                ++ cur;
            }
        }
        return sta.empty();
    }
};

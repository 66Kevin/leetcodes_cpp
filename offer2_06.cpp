class Solution {
public:
    vector<int> reversePrint(ListNode* head) {

        vector<int> result;
        vector<int> st;
        ListNode* cur = head;
        /* 将数据压入栈 */
        while(cur != NULL) {
            st.emplace_back(cur->val);
            cur = cur->next;
        }
        /* 将栈中的数据弹出 利用栈的性质可以反向输出结果 */
        while(!st.empty()) {
            result.emplace_back(st.back());
            st.pop_back();
        }
        return result;

    }
};

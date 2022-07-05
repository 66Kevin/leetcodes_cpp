class Solution {
  public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy_node = new ListNode(-1);
        dummy_node -> next = head;
        
        ListNode* pre = dummy_node;
        ListNode* cur = head;
        // find m node
        for(int i = 1; i < left; ++i){
            pre = cur;
            cur = cur -> next;
        }
        // reverse m node to n node
        // 头插法，只需要把cur->next插入到pre->next即可
        for(int i = left; i < right ; ++i){
            ListNode* tmp = cur -> next;
            cur -> next = tmp -> next;
            tmp -> next = pre -> next;
            pre -> next = tmp;
        }
        
        return dummy_node -> next;
    }
};

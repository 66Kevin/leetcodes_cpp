class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {

        if(head == NULL) return NULL;

        int count = 0;
        ListNode* tmp_node = head;
        while(tmp_node){
            tmp_node = tmp_node -> next;
            ++ count;
        }
        for(int i = 0; i < count - k; ++i){
            head = head -> next;
        }
        return head;
    }
};

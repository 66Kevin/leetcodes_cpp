class Solution {
    /*
    1.找到链表中点，拆分链表为l1，l2
    2.链表l2进行链表翻转
    3.按照题意重新组合链表
    */   
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        ListNode *pre = new ListNode();
        pre->next = head;
        //find mid node
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
            pre = pre->next;
            if(fast) fast = fast->next;
        }
        pre->next = nullptr;
        
        ListNode *l1 = head;
        ListNode *l2 = Reverse(slow);
        pre = new ListNode(-1);

        //按题意组合链表
        while(l2){
            pre->next = l1;
            pre = pre->next;
            l1 = l1->next;
            pre->next = l2;
            pre = pre->next;
            l2 = l2->next;
        }
        if(l1) pre->next = l1;
    }
private:
    ListNode* Reverse(ListNode *head){
        ListNode *pre = nullptr;
        ListNode *tmp = nullptr;
        while(head){
            tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};

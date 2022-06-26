class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
    // 分割
    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == nullptr) { // 处理特殊情况
            return head;
        }
        if (head->next == tail) { // 分割到只有一个节点的情况
            head->next = nullptr; // 注意要断开连接，方便后续合并
            return head;
        }
        ListNode* slow = head, *fast = head; //找mid：快指针走两步，慢指针走一步
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        ListNode* final_head = sortList(head, mid);
        ListNode* final_tail = sortList(mid, tail);
        
        return merge(final_head, final_tail);
    }
    // 归并
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        
        if (temp1 != nullptr) { // 如果temp1部分还有剩余，直接合并到temp的next
            temp->next = temp1;
        } else if (temp2 != nullptr) { // 如果temp2部分还有剩余，直接合并到temp的next
            temp->next = temp2;
        }
        
        return dummyHead->next;
    }
};

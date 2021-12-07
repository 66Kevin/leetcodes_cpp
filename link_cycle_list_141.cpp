#include <iostream>
#include <vector>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(struct ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        struct ListNode* slow = head;
        struct ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
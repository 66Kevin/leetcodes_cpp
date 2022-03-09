//
// Created by 王月艺 on 2022/3/9.
//
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int ans = 0;

        while(head){
            if(nums_set.count(head->val)){
                if(!head->next || !nums_set.count(head->next->val)){
                    ans += 1;
                }
            }
            head = head -> next;
        }
        return ans;
    }
};
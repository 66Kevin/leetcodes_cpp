#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        if(l1==nullptr){
            return l2; // 注意终止条件：当l1为空时返回l2剩余
        }

        if(l2==nullptr){
            return l1; // 注意终止条件
        }

        if (l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1; //注意返回，当遍历完后
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


ListNode* initList1(ListNode* head){//初始化第一个链表  
    ListNode* node1  = new ListNode(2);  
    head->next = node1;  
  
    ListNode* node2  = new ListNode(3);  
    node1->next = node2;  
  
    ListNode* node3  = new ListNode(6);  
    node2->next = node3;  
  
    ListNode* node4  = new ListNode(8);  
    node3->next = node4;  
    return head;  
}//initList1  
  
ListNode* initList2(ListNode* head){//初始化第二个链表  
    ListNode* node1  = new ListNode(1);  
    head->next = node1;  
  
    ListNode* node2  = new ListNode(2);  
    node1->next = node2;  
  
    ListNode* node3  = new ListNode(4);  
    node2->next = node3;  
  
    ListNode* node4  = new ListNode(5);  
    node3->next = node4;  
    return head;  
}//initList2  
  
//从头至尾遍历单链表  
void visitList(ListNode* head){  
    while(head!= NULL){  
        cout<<head->val<<endl;  
        head= head->next;  
    }  
}//visitList  
  
int main()    
{    
    //函数中初始化  
     cout<<"第一个链表:"<<endl;  
     ListNode* head1  = new ListNode(0);
     head1 = initList1(head1);  
     visitList(head1);  
  
     cout<<"第二个链表:"<<endl;  
     ListNode* head2  = new ListNode(-1);  
     head2 = initList2(head2);  
     visitList(head2);  
 
	 cout<<"合并后的新链表:"<<endl;  
	 Solution solution;
     ListNode* head = solution.mergeTwoLists(head1,head2);
     visitList(head);
  
     return 0;    
};
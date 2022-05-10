/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL) return NULL;
        unordered_map<Node*, Node*> hashmap;

        Node* cur = head;
        // loop1: copy all nodes
        while(cur){
            hashmap[cur] = new Node(cur->val);
            cur = cur -> next;
        }
        //loop2: assign next and random pointers
        cur = head;
        while(cur){
            Node* new_cur = hashmap[cur];
            new_cur -> next = hashmap[cur -> next];
            new_cur -> random = hashmap[cur -> random];

            cur = cur -> next;
        }

        return hashmap[head];
    }
};

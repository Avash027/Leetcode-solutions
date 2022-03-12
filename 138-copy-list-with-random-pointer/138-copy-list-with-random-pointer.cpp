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
        map<Node* , Node*> ump;
        
        Node* ptr = head;
        
        while(ptr){
            ump[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        
        ptr = head;
        
        while(ptr){
            ump[ptr]->next = ump[ptr->next];
            ump[ptr]->random = ump[ptr->random];
            ptr = ptr->next;
        }
        
        return ump[head];
    }
};
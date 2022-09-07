class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        
        Node* cur = head;
        
        while(cur){
            
            if(!cur->child){
                cur = cur->next;
                continue;
            }
            
            Node* temp = cur->child;
            
            while(temp->next)
                temp = temp->next;
            
            temp->next = cur->next;
            if(cur->next)
                cur->next->prev = temp;
            
            cur->next = cur->child;
            cur->next->prev = cur;
            cur->child = NULL;
            
        }
        
        return head;
        
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
               ListNode* itr = head , *prev = NULL;
        
        if(head == NULL) return nullptr;
        
        while(itr)
        {
            if(!itr->next) break;
            if(itr->val!=itr->next->val){
                prev = itr;
                itr = itr->next;  
                continue;
            }
            
            int cur = itr->val;
            
            while(itr and itr->val == cur) itr = itr->next;
            if(!prev) head = itr;
            else prev->next = itr;
        }
        
        return head;
    }
};
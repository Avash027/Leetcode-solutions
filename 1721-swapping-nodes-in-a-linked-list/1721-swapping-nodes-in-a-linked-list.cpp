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
private:
    ListNode* a;
    void traverse(ListNode* head, int beg, int& end,int k){
        if(!head) return;
        
        if(beg == k) a = head;
        
        traverse(head->next,beg+1,end,k);
        
        if(end == k) swap(a->val , head->val);
        ++end;
        
        
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        k--;
        int end = 0;
        traverse(head,0,end,k);
        
        return head;
    }
};
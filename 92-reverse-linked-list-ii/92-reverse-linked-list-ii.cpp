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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> st;
        int ind = 1;
        
        ListNode* itr = head;
        
        while(itr){
            if(ind>=left and ind<=right)
                st.push(itr->val);
            ind++;
            itr = itr->next;
        }
        
        itr = head;
        ind = 1;
        
        while(itr){
            if(ind>=left and ind<=right)
                itr->val = st.top() , st.pop();
            ind++;
            itr = itr->next;
        }
        
        
        return head;
        
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> ans;
    
  
public:
    vector<int> inorderTraversal(TreeNode* root) {
       if(root == NULL) return ans;
        
        stack<TreeNode*> st;
        
        TreeNode* cur = root;
        
        
        while(true){
            
            
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                if(st.empty()) break;
                cur = st.top();
                st.pop();
                
                ans.push_back(cur->val);
                cur = cur->right;
            }
            
        }
        
        return ans;
    }
};
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
    vector<int> preorderTraversal(TreeNode* root) {
        
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            
            if(cur==NULL) continue;
            
            ans.push_back(cur->val);
            
            st.push(cur->right);
            st.push(cur->left);
        }
        
        return ans;
    }
};
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return ans;
        
        stack<TreeNode*> st1 , st2;
        st1.push(root);
        
        while(!st1.empty()){
            TreeNode* cur = st1.top();
            st1.pop();
            
            st2.push(cur);
            
            if(cur->left) st1.push(cur->left);
            if(cur->right) st1.push(cur->right);
        }
        
        while(!st2.empty())
            ans.push_back(st2.top()->val),
            st2.pop();
        
        return ans;
    }
};
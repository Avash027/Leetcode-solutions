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
   int dfs(TreeNode* root, int mask){
        if(root == NULL)
            return 0;
    
        mask^=(1<<root->val);
       
         if(root->left == root->right){
            return __builtin_popcount(mask)<=1;
        }
       
        int cntLeft = dfs(root->left, mask);
        int cntRight = dfs(root->right, mask);
        
        return cntLeft + cntRight;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
       
        return dfs(root,0);
    }
};
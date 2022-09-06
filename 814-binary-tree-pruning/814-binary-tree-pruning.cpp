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
    bool dfs(TreeNode* root){
        if(root == NULL)
            return false;
        
        
        bool r = dfs(root->right);
        bool l = dfs(root->left);
        
        
        if(!r)
            root->right = NULL;
        
        if(!l)
            root->left = NULL;

        
        return (r || l || root->val);
        
        
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool isValidTree = dfs(root);
        if(!isValidTree)
            root = NULL;
        return root;
    }
};
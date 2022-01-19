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
    int ans = -1000000;
    
    int traverse(TreeNode* root){
        if(root == NULL) return 0;
        
        int lv = traverse(root->left);
        int rv = traverse(root->right);
        int v = root->val;
        
        ans = max({ans ,v+lv+rv,max(lv,rv)+v,v});
        
        return max(max(lv , rv), 0) + v;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return ans;
    }
};
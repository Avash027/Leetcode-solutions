/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        if(o==NULL) return nullptr;
        if(o == t) return c;
        
        TreeNode* l =getTargetCopy(o->left , c->left, t);
        TreeNode* r =getTargetCopy(o->right , c->right, t);
        
        if(l) return l;
        return r;
        
    }
};
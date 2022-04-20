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
    TreeNode *prev = NULL , *f = NULL , *s = NULL;
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        
        if(prev){
            if(prev->val > root->val){
                if(f == NULL) f = prev , s = root;
                else s = root;
            }
        }
            
        prev = root;
        
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(f->val , s->val);
    }
};
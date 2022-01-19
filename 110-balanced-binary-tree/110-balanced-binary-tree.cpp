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
    
    bool isbalanced = true;
    
    int height(TreeNode* root){
        if(root == NULL) return 0;
        
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        isbalanced = isbalanced && (abs(lheight-rheight)<=1);
        
        return max(lheight , rheight)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalanced;
    }
};
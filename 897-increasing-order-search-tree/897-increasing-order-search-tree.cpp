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
    TreeNode* newTree;
    
    void traverse(TreeNode* root){
        if(!root) return;
        traverse(root->left);
        newTree->right = new TreeNode(root->val);
        newTree = newTree->right;
        traverse(root->right);

    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        newTree = new TreeNode(0);
        TreeNode* ans = newTree;
        traverse(root);
        return ans->right;
    }
};
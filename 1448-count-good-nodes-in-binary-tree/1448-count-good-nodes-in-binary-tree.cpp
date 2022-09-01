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
public:
    int goodNodes(TreeNode* root , int mx = INT_MIN) {
            return !root ? 0:(root->val >= mx) + goodNodes(root->left , max(root->val,mx)) + goodNodes(root->right , max(root->val , mx)); 
    }
};
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
    bool deleteLeaf(TreeNode*& root , int target){
        if(root == NULL) return true;
        
        bool left = deleteLeaf(root->left , target);
        bool right = deleteLeaf(root->right , target);
        
        if(root->val == target and left and right)
            root = NULL;
        
        return root == NULL;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        deleteLeaf(root , target);
        return root;
    }
};
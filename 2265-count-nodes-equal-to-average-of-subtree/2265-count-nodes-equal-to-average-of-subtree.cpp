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
    
    int count = 0;
    
    pair<int,int> helper(TreeNode* root){
        if(!root)
            return {0,0};
        
        auto [childNumLeft, sumLeft] = helper(root->left);
        auto [childNumRight ,sumRight] = helper(root->right);
        
        int totalSize = childNumLeft + childNumRight + 1;
        int totalSum = root->val + sumLeft + sumRight;
        
        count+=(totalSum/totalSize == root->val);
        
        return {totalSize , totalSum};
        
        
    }
public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        
        return count; 
    }
};
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
constexpr int INF = 1e9;

class Solution {
private:
    int inorder(TreeNode* root, int& k){
        if(!root)
            return INF;
        
        int left =  inorder(root->left,k);
        
        int val = --k == 0?root->val:INF;
        
        int right = inorder(root->right,k);
        
        return min({left,right,val});
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root,k);
    }
};
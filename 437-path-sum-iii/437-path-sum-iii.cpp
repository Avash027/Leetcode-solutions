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
    int ans;
    long long target;
    
    void findPath(TreeNode* root , long long sum){
        if(root == NULL) return;
        
        sum+=root->val;
        if(sum == target) ans++;
        
        findPath(root->left , sum);
        findPath(root->right , sum);
        
    }
    
    void iterate(TreeNode* root){
        if(!root) return;
        
        findPath(root , 0LL);
        
        iterate(root->right);
        iterate(root->left);
        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        target = targetSum;
        iterate(root);
        return ans;
    }
};
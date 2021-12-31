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

const int INF = 1000000;

class Solution {
private:
    
    int ans;
    
    // min max
    pair<int,int> traverse(TreeNode* root){
        if(root == NULL) return {INF,-1};
        
        pair<int,int> r_val = traverse(root->right);
        pair<int,int> l_val = traverse(root->left);
        
        if(r_val.first!=INF) ans = max(ans , abs(root->val - r_val.first));
        if(l_val.first!=INF) ans = max(ans , abs(root->val - l_val.first));
        if(r_val.second!=-1) ans = max(ans , abs(root->val - r_val.second));
        if(l_val.second!=-1) ans = max(ans , abs(root->val - l_val.second));
        
        return {min({root->val , l_val.first, r_val.first}) ,
                max({root->val , l_val.second, r_val.second})};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        ans = -INF; 
        traverse(root);
        return ans;
    }
};
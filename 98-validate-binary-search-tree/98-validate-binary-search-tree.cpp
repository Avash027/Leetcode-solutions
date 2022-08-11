constexpr long long INF = 1e10+7;

class Solution {
private:
    bool ans = true;
    
    // min , max
    pair<long long,long long> check(TreeNode* root){
        if(root == NULL)
            return {INF , -INF};
        
        auto left = check(root->left);
        auto right = check(root->right);
        
        
        if(root->val <= left.second || root->val >= right.first){
            ans = false;
        }
        
        return {
            min({1LL*root->val , left.first , right.first}),
            max({1LL*root->val , right.second , left.second})
        };
        
    }
    
public:
    bool isValidBST(TreeNode* root) {
          check(root);
        return ans;
    }
};
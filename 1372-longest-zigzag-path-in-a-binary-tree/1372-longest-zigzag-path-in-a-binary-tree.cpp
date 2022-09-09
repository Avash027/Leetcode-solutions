class Solution {
private:
    
    int ans = -1;
    
    pair<int,int> dfs(TreeNode* root){
        if(root == NULL)
            return {0,0};
        
        pair<int,int> leftChild = dfs(root->left);
        pair<int,int> rightChild = dfs(root->right);
        
        ans = max({ans,1 + leftChild.second, 1 + rightChild.first});
        
        return {
            1 + leftChild.second,
            1 + rightChild.first
        };
        
    }
    
public:
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans-1;
    }
};
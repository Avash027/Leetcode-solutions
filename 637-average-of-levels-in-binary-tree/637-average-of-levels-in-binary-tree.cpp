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
    vector<vector<long long>> lev;
    
    void dfs(TreeNode* root,int level = 0){
        if(!root)
            return;
        
        if(lev.size()<=level) lev.push_back(vector<long long>{});
        
        lev[level].push_back(root->val);
        
        dfs(root->left , level+1);
        dfs(root->right , level+1);
        
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(root);
        vector<double> ans;
        
        for(auto l:lev){
            ans.push_back(1.0*accumulate(begin(l),end(l) , 0LL)/l.size());

        }
        
                    
        return ans;
        
    }
};
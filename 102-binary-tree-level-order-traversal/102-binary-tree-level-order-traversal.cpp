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
    vector<vector<int>> ans;
    
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == NULL) return ans;
        
        queue<pair<TreeNode* , int>> q;
        q.push({root , 0});
        
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            if(ans.size()<=depth) ans.push_back(vector<int>{});
            
            ans[depth].push_back(node->val);
            
            if(node->left) 
                q.push({node->left , depth+1});
            
            if(node->right)
                q.push({node->right , depth+1});
        }
        
        return ans;
    }
};
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
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int maxh = 0,ans = 0;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            int h = q.front().second;
            
            q.pop();
            
            if(h>maxh) maxh = h , ans = 0;
            if(h == maxh) ans+=cur->val;
            
            if(cur->right)
                q.push(make_pair(cur->right , h+1));
            if(cur->left)
                q.push(make_pair(cur->left , h+1));
        }
        
        return ans;
    }
};
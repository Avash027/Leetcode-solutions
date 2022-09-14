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
    int pseudoPalindromicPaths (TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        int ans = 0;
        
        q.push({root,1<<(root->val)});
        
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            int mask = q.front().second;
            q.pop();
            
            bool isLeaf = true;
            
            if(cur->left){
                isLeaf = false;
                q.push({cur->left,mask^(1<<(cur->left->val))});
                
            } 
            
            if(cur->right) {
                isLeaf = false;
                q.push({cur->right,mask^(1<<(cur->right->val))});

            }
            
            if(isLeaf){
                cout<<mask<<"\n";
                ans += __builtin_popcount(mask)<=1;
            }
        }
        
        return ans;
        
    }
};
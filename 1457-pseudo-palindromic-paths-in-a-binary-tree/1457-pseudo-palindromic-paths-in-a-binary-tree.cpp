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
    bool isPal(vector<int>&freq){
        int cntOdd = 0;
        for(auto&e:freq) cntOdd += (e&1);
        
        return cntOdd<=1;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        
        queue<pair<TreeNode*, vector<int>>> q;
        vector<int> temp(10 , 0);
        temp[root->val]++;
        
        int ans = 0;
        
        q.push({root,temp});
        
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            vector<int> freq =q.front().second;
            q.pop();
            
            bool isLeaf = true;
            
            if(cur->left){
                isLeaf = false;
                freq[cur->left->val]++;
                q.push({cur->left, freq});
                freq[cur->left->val]--;
            } 
            
            if(cur->right) {
                isLeaf = false;
                freq[cur->right->val]++;
                q.push({cur->right,freq});
                freq[cur->right->val]--;
            }
            
            if(isLeaf){
                ans += isPal(freq);
            }
        }
        
        return ans;
        
    }
};
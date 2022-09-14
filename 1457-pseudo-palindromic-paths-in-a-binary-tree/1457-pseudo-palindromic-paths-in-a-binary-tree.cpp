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
    
    int dfs(TreeNode* root, vector<int>& freq){
        if(root == NULL)
            return 0;
        
        if(root->left == root->right){
            freq[root->val]++;
            int cnt = isPal(freq);
            freq[root->val]--;
            return cnt;
        }
        
        freq[root->val]++;
        int cntLeft = dfs(root->left, freq);
        int cntRight = dfs(root->right, freq);
        freq[root->val]--;
        
        return cntLeft + cntRight;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        
        return dfs(root,freq);
    }
};
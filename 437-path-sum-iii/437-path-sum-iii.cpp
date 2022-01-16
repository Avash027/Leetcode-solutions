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
    int target;
    unordered_map<int,int> umpp;
    
    void iterate(TreeNode* root , int sum = 0){
        if(root == NULL) return;
        
        sum+=root->val;
        
        ans+=umpp[sum - target];
        umpp[sum]++;
        
        iterate(root->left , sum);
        iterate(root->right , sum);
        umpp[sum]--;
    }
    
   
public:
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        target = targetSum;
        umpp[0]=1;//for the root node
        iterate(root);
        return ans;
    }
};
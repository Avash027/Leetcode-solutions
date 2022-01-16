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
    
    void genPath(TreeNode* root , int sum , int target , vector<int> path){
        if(root == NULL) return;
        
         
        path.push_back(root->val);
        sum+=root->val;

        if(root->left == root->right){
            
            if(sum == target){
                ans.push_back(path);
            }
            return ;
        }
        
       
        
        genPath(root->left , sum , target , path);
        genPath(root->right , sum , target,path);
        
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        genPath(root , 0 , targetSum , vector<int>{});
        return ans;
    }
};
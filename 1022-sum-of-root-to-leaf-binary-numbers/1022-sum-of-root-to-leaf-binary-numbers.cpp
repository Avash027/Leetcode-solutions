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
    int ans = 0;
    
    inline bool isLeaf(TreeNode* root) const{
        return root->left == NULL and root->right == NULL;
    }
    
    int convert(string b){
        int value = 0;
        int base = 1;
        
        for(int i = (int)b.size()-1;i>=0;i--){
            value+=(b[i]-'0')*base;
            base*=2;
        }
        
        return value;
    }
    
    void sumUtil(TreeNode* root , string bits=""){
        if(root == NULL) return;
        
        bits.push_back(char('0'+root->val));
        
        if(isLeaf(root)){
            ans+=convert(bits);
            return;
        }
        
        sumUtil(root->left , bits);
        sumUtil(root->right , bits);
        
        
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        sumUtil(root);
        return ans;
    }
};
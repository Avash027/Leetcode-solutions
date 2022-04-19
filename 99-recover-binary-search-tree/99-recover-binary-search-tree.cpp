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
vector<int> ls;
int i = 0;
    
 void inOrder(TreeNode* root){
     if(!root) return;
     inOrder(root->left);
     ls.push_back(root->val);
     inOrder(root->right);
 }
    
  void inOrder1(TreeNode* root){
      if(!root) return;
      inOrder1(root->left);
      root->val = ls[i++];
      inOrder1(root->right);
  }
    
public:
    void recoverTree(TreeNode* root) {
        inOrder(root);
        sort(begin(ls),end(ls));
        inOrder1(root);
    }
};
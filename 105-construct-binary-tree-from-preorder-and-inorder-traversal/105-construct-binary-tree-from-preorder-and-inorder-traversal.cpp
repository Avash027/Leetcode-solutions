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
       TreeNode* buildTreeUtil(     vector<int>& inorder , int iStart , int iEnd , 
                                    vector<int>& preorder , int pStart , int pEnd,
                                    map<int,int>& ump){
        
        if(pStart>pEnd or iStart>iEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pStart]);
        
        int ind = ump[preorder[pStart]];
        
        root->left = buildTreeUtil(inorder , iStart , ind-1 , preorder , pStart+1 , pStart + ind -iStart , ump );
        root->right = buildTreeUtil(inorder , ind+1 , iEnd , preorder ,pStart + ind -iStart+1 , pEnd , ump );
        
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> ump;
        
        for(int i = 0;i<preorder.size();i++)
            ump[inorder[i]] = i;
        
        return buildTreeUtil(inorder , 0  ,inorder.size()-1 , preorder , 0 , preorder.size()-1 ,ump);
        
    }
};
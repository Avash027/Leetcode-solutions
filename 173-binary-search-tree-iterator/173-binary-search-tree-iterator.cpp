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
class BSTIterator {
private:
    TreeNode* flatRoot;
    
    void inorder(TreeNode* root , TreeNode*& temp){
        if(!root) return;
        
        inorder(root->left,temp);
        
        temp->left = NULL;
        temp->right = new TreeNode(root->val);
        temp = temp->right;
        
        inorder(root->right,temp);
    }
    
public:
    BSTIterator(TreeNode* root) {
        TreeNode* temp = new TreeNode(-1);
         flatRoot = temp;
        
        inorder(root , flatRoot);
        flatRoot->left = NULL;
        flatRoot->right = NULL;
        
        flatRoot = temp->right;
 
    }
    
    int next() {
        int val = flatRoot->val;
        flatRoot = flatRoot->right;
        
        return val;
    }
    
    bool hasNext() {
        return flatRoot;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
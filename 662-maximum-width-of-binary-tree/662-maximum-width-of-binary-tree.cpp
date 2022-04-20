class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode* , unsigned long long>> q;
        q.push({root , 1});
        unsigned long long ans = 1;
        
        while(!q.empty()){
            int level_size = q.size();
            int offset = q.front().second;
            
            unsigned long long f = 0 , l = 0;
            
            //Traversing each node in the leve
            for(int i = 0;i<level_size;i++){
                unsigned long long ind = q.front().second - offset;
                TreeNode* cur = q.front().first;
                q.pop();
                
                if(i == 0) f = ind;
                if(i == level_size - 1) l = ind;
                
                if(cur->left)
                    q.push({cur->left , 2*ind});
                if(cur->right)
                    q.push({cur->right , 2*ind+1});
            }
            
            ans = max(ans , l - f+1);
        }
        
        return (int)ans;                
    }
};
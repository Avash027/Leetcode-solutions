/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root == NULL) return ans;
        
        queue<pair<Node* , int>> q;
        
        q.push({root , 0});
        
        
        while(!q.empty())
        {
            Node* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            if(ans.size()<=depth) ans.push_back(vector<int>{});
            
            ans[depth].push_back(node->val);
            
            for(const auto &e:node->children)
            {
                if(e == NULL) continue;
                q.push({e , depth+1});
            }
        }
        
        return ans;
        
    }
};
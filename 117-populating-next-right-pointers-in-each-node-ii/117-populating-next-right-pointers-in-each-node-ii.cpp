
class Solution {
public:
    Node* connect(Node* root) {

        Node* r = root;
        
        /**
        * Outer loop goes from one level to another
        **/
        
        while(r){
            Node* tempNode = new Node(-1);
            Node* temp = tempNode;
            
            while(r){ // This one travels each node in the level
                if(r->left)
                    temp->next = r->left , temp = temp->next;
                if(r->right)
                    temp->next = r->right, temp = temp->next;
                
                r = r->next; // Go to the siblings
            }
            
            r = tempNode->next;
        }
        
        return root;
    }
};
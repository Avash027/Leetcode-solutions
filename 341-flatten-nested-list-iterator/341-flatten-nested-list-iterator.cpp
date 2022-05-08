class NestedIterator {
private:
    stack<NestedInteger*> nodes;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; --i) {
            nodes.push(&nestedList[i]);
        }
    }
    
    int next() {
        int result = nodes.top()->getInteger();
        nodes.pop();
        return result;
    }
    
    bool hasNext() {
        while(!nodes.empty()) {
            NestedInteger* curr = nodes.top();
            if (curr->isInteger()) {
                return true;
            }
            
            nodes.pop();
            
            vector<NestedInteger>& adjs = curr->getList();
            for(int i = adjs.size() - 1; i >= 0; --i) {
                nodes.push(&adjs[i]);
            }
        }
        
        return false;
    }
};

//Check notes
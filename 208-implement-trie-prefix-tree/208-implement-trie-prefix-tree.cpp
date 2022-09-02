struct TrieNode{
    TrieNode* next[26];
    int countPrefix =0;
    int countCompleteWord = 0;
    
    void append(char& c , TrieNode* newNode){
        next[c-'a'] = newNode;
    }
    
    TrieNode* get(char& c){
        return next[c-'a'];
    }
    
    bool containsKey(char&c){
        return next[c-'a']!=NULL;
    }
    
    void increasePrefix(){
        this->countPrefix++;
    }
    
    void increaseEnd(){
        this->countCompleteWord++;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode* root = this->root;
        
        for(char&c:word){
            if(!root->containsKey(c))
                root->append(c , new TrieNode());
            
            root = root->get(c);
            root->increasePrefix();
        }
        
        root->increaseEnd();
    }
    
    bool search(string word) {
        TrieNode* node = this->root;
        
        for(char&c:word){
            if(!node->containsKey(c))
                return false;
            
            node = node->get(c);
        }
        
        return node->countCompleteWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = this->root;
        
        for(char&c:prefix){
            if(!node->containsKey(c))
                return false;
            
            node = node->get(c);
        }
        
        return node->countPrefix;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
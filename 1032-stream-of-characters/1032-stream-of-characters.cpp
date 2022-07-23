struct Node{
    Node* links[26];
    int count_ends = 0;
    
    bool containsKey(const char&ch){
        return links[ch - 'a'] != NULL;
    }

    Node* get(char& ch) {
        return links[ch - 'a'];
    }
    void put(char& ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    void increaseEnd() {
        count_ends++;
    }
    
    bool isEnd() {
        return count_ends != 0;
    }
};


struct Trie{
private:
    Node* root;
    
public:
    Trie(){
        root = new Node();
    }
    
    void insert(string&s){
        reverse(begin(s),end(s));
        
        Node* node = root;
        
        for(char&c:s){
            if(!node->containsKey(c))
                node->put(c , new Node());
            node = node->get(c);
        }
        
        node->increaseEnd();
    }
    
    bool query(string& s){
        Node* node = root;
        for(int i = s.size()-1;i>=0;i--){
            if(node->isEnd())
                return true;
            
            if(!node->containsKey(s[i]))
                return false;

            node = node->get(s[i]);
        }
        
        return node->isEnd();
    }
    
};


class StreamChecker {
private:
    Trie t;
    string stream;
public:
    StreamChecker(vector<string>& words) {
        for(string&s:words)
            t.insert(s);
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        return t.query(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
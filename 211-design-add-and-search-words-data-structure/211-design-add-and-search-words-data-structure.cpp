struct Node
{
    Node* links[50];
    int count_ends = 0;
    int count_prefix = 0;

    bool containsKey(const char&ch)
    {
         return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }


    void increasePrefix() {
        count_prefix++;
    }

    void increaseEnd() {
        count_ends++;

    }
    bool isEnd() {
        return count_ends != 0;
    }

    int getEnd() {
        return count_ends;
    }

    int getPreix() {
        return count_prefix;
    }

    void decreasePrefix() {
        count_prefix--;
    }

    void decreaseEnds() {
        count_ends--;
    }

};


struct Trie
{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }

    void insert(const string&s)
    {
        Node *node = root;
        for (int i = 0; i < s.size(); i++) {
            if (!node->containsKey(s[i])) {
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int equalsTo(string s,int start = 1,Node* node = NULL)
    {
        if(node == NULL and !start) return 0; 
        if(node == NULL) node = root;        
        int i = -1;
        int n = s.size();
        for (const char&c : s)
        {
            i++;
            if(c=='.'){
                int found = 0;
                for(char x='a';x<='z';x++){
                    if(!node->containsKey(x)) continue;
                    found |= equalsTo(s.substr(i+1),0,node->get(x));
                }
                return found;
            }
            if (!node->containsKey(c)) return 0;
            node = node->get(c);
        }

        return node->getEnd();
    }

    
};


class WordDictionary {
private:
    Trie t;
    
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.equalsTo(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
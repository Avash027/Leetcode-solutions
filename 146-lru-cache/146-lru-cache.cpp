struct Node {
    int val;
    int key;
    struct Node* next , *prev;

    Node() {
        next = prev = NULL;
    }

    Node(int key,int val) {
        this->key = key;
        this->val = val;
        next = prev = NULL;
    }
};

struct Dlist {
    Node * head , *tail;

    Dlist() {
        head = tail = NULL;
    }

    Node* insert(int key,int val) {
        Node* node = new Node(key,val);

        if (!head) {
            head = node;
            tail = node;
            return node ;
        }

        tail->next = node;
        node->prev = tail;
        tail = tail->next;
        return node;
    }

    void removeTail() {
        if(tail == NULL) return;
        tail = tail->prev;
        tail->next = NULL;
    }

    void removeNode(Node * node) {

        if (node == head) {
            head = head->next;
            return;
        }
        else if (node == tail) {
            tail = tail->prev;
            delete tail->next;
            return;
        }

        Node* p = node->prev;
        p->next = node->next;
        p->next->prev = p;
        delete node;
    }

    Node* insertAtHead(int key,int val) {

        Node* node = new Node(key,val);


        if (head == NULL) {
            head = node;
            tail = node;
            return node;
        }

        head->prev = node;
        node->next = head;
        head = head->prev;

        return node;
    }

    Node* shiftToHead(Node* node) {
        int val = node->val;
        int key = node->key;
        removeNode(node);
        Node* newNode =  insertAtHead(key,val);
        return newNode;
    }

    void print() {
        Node* temp = head;
        while (temp) cout << temp->val << " ", temp = temp -> next;
    }

};


class LRUCache {

private:
    int capacity;
    Dlist list;
    unordered_map<int,Node*> cache;
public:
    LRUCache(int capacity) {
    this->capacity = capacity;    
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        
        
        Node* cur = cache[key];
        int val =cur->val;
        cache[key] = list.shiftToHead(cur);
        
        return val;
        
    }
    
    void put(int key, int value) {
        
        if(cache.find(key) !=cache.end()){
            
            list.removeNode(cache[key]);
        cache.erase(key);
            }
        
        Node* node = list.insertAtHead(key,value);
        cache[key] = node;
       
        if(cache.size() > capacity){
            int key = list.tail->key;
            cache.erase(key);
            list.removeTail();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
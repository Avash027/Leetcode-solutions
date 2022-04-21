class MyHashSet {
public:
    int val[1<<19];
    MyHashSet() {
        memset(val, 0, sizeof(val));
    }
    
    void add(int key) {
        val[hash(key)] = 1;
    }
    
    void remove(int key) {
        val[hash(key)] = 0;
    }
    
    bool contains(int key) {
        return val[hash(key)] == 1;
    }
    
    int hash(int key){
        long long t = (long long)1298809*key; //322169
        return (t & (1<<24)-1)>>5;
    }
};

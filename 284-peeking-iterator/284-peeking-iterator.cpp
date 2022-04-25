class PeekingIterator : public Iterator {
private:
    bool hasNxt;
    int nxt;
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {

	    
        hasNxt = Iterator::hasNext();
        
        if(hasNxt)
            nxt = Iterator::next();

	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nxt;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        hasNxt = Iterator::hasNext();
        int val = nxt;
        if(hasNxt)
            nxt = Iterator::next();
            
        return val;
	}
	
	bool hasNext() const {
	    return hasNxt;
	}
};
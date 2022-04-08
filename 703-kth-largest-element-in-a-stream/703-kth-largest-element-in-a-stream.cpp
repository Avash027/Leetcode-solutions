class KthLargest {
private:
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for(int&e:nums)
            this->pq.push(-e);
        
        while(pq.size()>k) pq.pop();
    }
    
    int add(int val) {
        this->pq.push(-val);
        while(this->pq.size()>this->k) this->pq.pop();
        
        return -this->pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
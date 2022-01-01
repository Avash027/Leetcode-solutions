

class Solution {
private:
    vector<int> original_nums;
    vector<int> shuffeled_nums;
    int n;
public:
    Solution(vector<int>& nums) {
        srand(time(0));
        this->original_nums = nums;
        this->shuffeled_nums = nums;
        this->n = nums.size();
    }
    
    vector<int> reset() {
        return this->original_nums;
    }
    
    vector<int> shuffle() {
        for(int _ = 0;_<100;_++){
            int ind1 = rand()%n;
            int ind2 = rand()%n;
            
            swap(shuffeled_nums[ind1],shuffeled_nums[ind2]);
        }
        return shuffeled_nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
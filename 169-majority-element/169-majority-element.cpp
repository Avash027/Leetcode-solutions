class Solution {
public:
    int majorityElement(vector<int>& nums) {
    
        int count = 0;
        int element = 0;
        
        for(int&e:nums){
            if(count==0) element = e;
             if(element!=e) count--;
            else count++;
        }
        
        return element;
    }
};
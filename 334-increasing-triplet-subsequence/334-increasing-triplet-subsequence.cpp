class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1 = INT_MAX, num2 = INT_MAX;
        
        for(int e:nums){
            if(e<=num1) num1 =e ;
            else if(e<=num2) num2=e;
            else return true;
        }
        
        return false;
    }
};
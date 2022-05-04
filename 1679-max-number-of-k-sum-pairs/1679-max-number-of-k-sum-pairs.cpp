class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        
        int mx_ops = 0;
        
        for(int&e:nums){
            if(freq[k - e])
                freq[k - e]-- , mx_ops++;
            else
                freq[e]++;
        }
        
        return mx_ops;
    }
};
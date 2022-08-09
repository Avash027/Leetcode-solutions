constexpr int MOD = 1e9+7;

class Solution {
private:
    
    unordered_map<int,int> nums;
    
    int count(int i , vector<int>&arr,unordered_map<int,int>& ump){
        if(i==0)
            return nums[arr[i]] =  1;
        
        if(nums.count(arr[i])!=0)
            return nums[arr[i]];
        
        long long ans = 1;
        
        for(int j = i-1;j>=0;j--){
            if(arr[i]%arr[j] == 0 and ump.find(arr[i]/arr[j])!=ump.end()){
                int ind =  ump[arr[i]/arr[j]];
                
                ans = (ans%MOD + (1LL*count(j,arr,ump)%MOD * 1LL*count(ind , arr,ump)%MOD))%MOD;

            }   
        }
        

        
        return nums[arr[i]] = ans%MOD;
        
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(begin(arr),end(arr));
        
        unordered_map<int,int> ump;
        
        for(int i = 0;i<arr.size();i++)
            ump[arr[i]] = i;
        
        int ans = 0;
        
        for(int i = arr.size()-1;i>=0;i--)
            (ans+=count(i,arr,ump))%=MOD;
        

        
        return ans;
    }
};
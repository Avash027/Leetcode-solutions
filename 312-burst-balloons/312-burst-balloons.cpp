class Solution {
private:
    vector<vector<int>> dp;
    
    int findAns(vector<int>&nums,int i,int j){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mx = -1;
        for(int k = i;k<=j;k++){
            int value = nums[i-1]*nums[k]*nums[j+1];
            
            mx = max(mx , findAns(nums,i,k-1) + findAns(nums,k+1,j) + value);
        }
        
        return dp[i][j] = mx;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        const int n = nums.size();
        
        dp.assign(n+1 , vector<int>(n+1 , -1));
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        return findAns(nums,1,n);
    }    
};
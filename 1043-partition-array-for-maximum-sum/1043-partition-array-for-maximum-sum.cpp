class Solution {
private:
    vector<vector<int>> dp;
    int maxSum(vector<int>&arr , int i , int j,int k){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mx = 0;
        int mx_elem = arr[i];
        
        for(int ii = i , cnt = 0;ii<=j and cnt<k;ii++,cnt++){ 
            mx_elem = max(mx_elem , arr[ii]);
            mx = max(mx_elem*(ii - i+1) + maxSum(arr , ii+1,j,k) , mx);
           
        }

        
        return dp[i][j] = mx;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();
        dp.assign(n+1 , vector<int>(n+1,-1));
        return maxSum(arr , 0 , n-1,k);
    }
};
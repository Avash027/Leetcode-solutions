class Solution {
private:
//     vector<vector<int>> dp;
//     int maxSum(vector<int>&arr , int i , int j,int k){
//         if(i>j) return 0;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         int mx = 0;
//         int mx_elem = arr[i];
        
//         for(int ii = i , cnt = 0;ii<=j and cnt<k;ii++,cnt++){ 
//             mx_elem = max(mx_elem , arr[ii]);
//             mx = max(mx_elem*(ii - i+1) + maxSum(arr , ii+1,j,k) , mx);
           
//         }

        
//         return dp[i][j] = mx;
//     }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();
        vector<int> dp(n+1 , 0);
        
        for(int i = n-1;i>=0;i--){
            int mx = -1;
            
            for(int j = i,cnt = 0;j<n and cnt<k;j++,cnt++){
                mx = max(mx , arr[j]);
                dp[i] = max(dp[i] , mx*(j-i+1) + dp[j+1]);
            }
        }
        
        return dp[0];
       
    }
};
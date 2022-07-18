class Solution {
public:
    int max_score(vector<vector<int>>& arr , int i,int k
                 ,vector<vector<int>>& dp){
        if(i == arr.size() || k == 0)
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int ans = 0;
        
        for(int j = i;j<arr.size();j++){
            
            int lo = j+1 , hi = arr.size()-1;
            int mx = arr.size();
            
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(arr[mid][0] > arr[j][1])
                    mx = mid , hi = mid-1;
                else 
                    lo = mid+1;
            }
            
            ans = max(ans , max_score(arr,mx,k-1,dp) + arr[j][2]);
            
        }
        
        return dp[i][k] = ans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> dp(events.size() , vector<int>(k+1,-1));
        sort(begin(events),end(events));       
        return max_score(events,0,k,dp);
    }
};
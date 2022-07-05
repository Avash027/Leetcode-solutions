class Solution {
private:
    static const int INF = 1e7;
    int dp[1010][11];
    
    int count(vector<int>&arr, int i, int d){
        if(i == arr.size() and d == 0)
            return 0;
        if(i == arr.size() or d == 0)
            return INF;
        
        if(dp[i][d] != -1)
            return dp[i][d];
        
        int cost = 0;
        int ans = INF;
        
        for(int j = i;j<arr.size();j++){
            cost = max(arr[j],cost);
            ans = min(ans,count(arr,j+1,d-1) + cost);
        }
        
        return dp[i][d] = ans;
        
    }
    
    
public:
    int minDifficulty(vector<int>& arr, int d) {
        memset(dp,-1,sizeof(dp));
        
        int ans = count(arr,0,d);
        
        return ans == INF?-1:ans;
    }
};
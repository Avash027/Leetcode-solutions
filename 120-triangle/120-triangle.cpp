constexpr int INF = 1000000;

class Solution {
private:
    
    int minPathSum(vector<vector<int>>& arr
                   ,int row
                   ,int cur
                   ,vector<vector<int>>& dp){
        
        if(row>=arr.size())
            return INF;
        
        if(cur >= arr[row].size() or cur<0)
            return INF;
        
        if(row == arr.size()-1)
            return arr[row][cur];
        
        if(dp[row][cur]!=-1) return dp[row][cur];
        
        return dp[row][cur] = arr[row][cur] +  min(minPathSum(arr,row+1,cur,dp) , minPathSum(arr,row+1,cur+1,dp));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        const int n = triangle.size();
        
        vector<vector<int>> dp(n , vector<int>(n,-1));
        
        return minPathSum(triangle , 0 , 0,dp);
    }
};
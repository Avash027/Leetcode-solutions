constexpr int INF = 1e8;

class Solution {
private:
    
//     vector<int> dp;
    
    bool isPalindrome(string& s){
        int i = 0 , j = s.size()-1;
        
        while(i<=j)
            if(s[i++]!=s[j--]) return false;
        
        return true;
    }
    
//     int minPal(string&s , int i, int n){
//         if(i >= n) return 0;
        
//         int ans = INF;
       
//         if(dp[i]!=-1) return dp[i];
        
//         string cur = "";
//         for(int j = i;j<n;j++){
            
//             cur.push_back(s[j]);
//             if(isPalindrome(cur)) ans = min(ans , minPal(s , j+1,n)+1);
        
//         }
        
//         return dp[i] = ans;
        
//     }
public:
    int minCut(string s) {
        const int n = s.size();
        // dp.assign(n+1,-1);
        // return minPal(s , 0 , n)-1;
    
        vector<int> dp(n+1 , INF);
        dp[n] = 0;
        
        for(int i = n-1;i>=0;i--){
            string cur = "";
            
            for(int j = i;j<n;j++){
                cur.push_back(s[j]);
                if(isPalindrome(cur)) dp[i] = min(dp[i] , dp[j+1]+1);
            }  
        }
        
        return dp[0]-1;
    }
};
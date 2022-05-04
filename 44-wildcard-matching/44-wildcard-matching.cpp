class Solution {
private:
    
    bool recur(string&s, string&p , int n , int m , vector<vector<int>>& dp){
       
        if(n == 0 and m == 0)
            return true;
        
        if(n == 0 and m>0){
            bool ok = true;
            
            while(m-1>=0)
                ok&=p[m-1]=='*' , m--;
            return ok;
        }
        
        if(m == 0 and n>0){
            
            bool ok = true;
            
            while(n-1>=0)
                ok&=s[n-1]=='*' , n--;
            
            return ok;
        }
         
        if(dp[n][m]!=-1) return dp[n][m];
        
        bool isSame = false;
        
        if(s[n-1]!='*' and p[m-1]!='*'){
            if(s[n-1] == p[m-1] or s[n-1]=='?' or p[m-1] == '?')
                isSame = recur(s,p,n-1,m-1,dp);
        }
        else{
           isSame = recur(s,p,n-1,m,dp) or recur(s,p,n,m-1,dp);
        }
        
        return dp[n][m] = isSame;
        
        
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1 , vector<int>(p.size()+1 , -1));
        
        return recur(s,p,s.size(),p.size(),dp);
    }
};

/**
* NOTES:


**/
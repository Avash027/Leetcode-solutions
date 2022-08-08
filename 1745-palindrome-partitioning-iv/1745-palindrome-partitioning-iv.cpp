class Solution {
private:
    
    bool dp[2010][4];
    
    bool isPal(const string&s , int l , int r){
        while(l<r) 
            if(s[l++] != s[r--])
                return false;
        
        return true;
    }
    
    
//     bool check(string&s , int l,int cnt = 0){
    
//         if(cnt>3)
//             return false;
        
//         if(l == s.size()){
//             return cnt == 3;
//         }
        
//         if(dp[l][cnt]!=-1)
//             return dp[l][cnt];
        
//         bool ans = false;
        
//         for(int i = l;i<s.size();i++)
//             if(isPal(s , l , i))
//                 ans |= check(s , i+1,cnt+1);
        
//         return dp[l][cnt] = ans;
//     }
    
public:
    bool checkPartitioning(string s) {
        memset(dp,false,sizeof(dp));
        const int N = s.size();
        
        for(int i = 0;i<N;i++)
            for(int j = i;j>=0;j--){
                if(!isPal(s,j,i)) continue;
                
                if(j == 0){
                    dp[i][1] = true;
                    continue;
                }
                
                for(int k = 1;k<=2;k++)
                    if(dp[j-1][k])
                        dp[i][k+1] = true;
                
            }
        

        
        return dp[N-1][3];
    }
};
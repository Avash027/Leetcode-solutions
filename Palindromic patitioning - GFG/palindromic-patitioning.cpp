// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

constexpr int INF = 1e6;

class Solution{
private:
    bool isPal(string s){
        int lo = 0 , hi = (int)s.size()-1;
        while(lo<=hi) if(s[lo++]!=s[hi--]) return false;
        return true;
    }
    
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        bool dp[n][n];
        
        int ans[n];
        
        for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) dp[i][j] = 0;
        
        for(int i = 0;i<n;i++){
            int temp_min = i;
            
            for(int j = 0;j<=i;j++){
                
                dp[j][i] = (str[i] == str[j]) and(i-j<2 or dp[j+1][i-1]);
                
                if(dp[j][i])
                    temp_min = min(temp_min , ((j==0)?0:ans[j-1]+1));
                
            }
            
            ans[i] = temp_min;
        }        
        
            return ans[n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
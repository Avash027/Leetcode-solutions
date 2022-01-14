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
        int dp[n];
        fill(dp , dp+n , INF);
        
        for(int i = 0;i<n;i++)
        {
            if(isPal(str.substr(0,i+1))){
                dp[i]=1;
                continue;
            }
            
            for(int j = i-1;j>=0;j--)
            {
                if(dp[j] and isPal(str.substr(j+1,i-j)))
                    dp[i] = min(dp[i] , dp[j]+1);
            }
        }

        
        return dp[n-1]==INF?0:dp[n-1]-1;

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
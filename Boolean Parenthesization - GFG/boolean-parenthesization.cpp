// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


constexpr int MOD = 1003;

class Solution{
private:

    vector<vector<vector<int>>> dp;

    int count(string&s , int i , int j,bool isTrue){
        if(i>j) return 0;
        if(i == j){
            if(isTrue == true and s[i]=='T') return 1;
            else if(isTrue == false and s[i] == 'F') return 1;
            else return 0;
        }
        
        int cnt = 0;

        
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        
        for(int k = i+1;k<=j-1;k+=2){
           
            
            
                int left = count(s,i,k-1,true)%MOD;
                int right = count(s,k+1,j,true)%MOD;
                int leftf = count(s,i,k-1,false)%MOD;
                int rightf = count(s,k+1,j,false)%MOD;
                
                
            
            if(s[k] == '&'){
                if(isTrue) (cnt+=left*right)%=MOD;
                else (cnt+= leftf*right + rightf*left + leftf*rightf)%=MOD;
            }
            else if(s[k] == '|'){
                if(isTrue) (cnt+=left*right + left*rightf + leftf*right)%=MOD;
                else (cnt+= leftf*rightf)%=MOD;
                
            }
            else{
                if(isTrue) (cnt+=left*rightf + leftf*right)%=MOD;
                else (cnt+= leftf*rightf + left*right)%=MOD;
            }
        }
        
        return dp[i][j][isTrue] = cnt;
        
    }
public:
    int countWays(int N, string S){
        dp.assign(N+1 , vector<vector<int>>(N+1, vector<int>(2,-1)));
       return count(S , 0,N-1 , true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
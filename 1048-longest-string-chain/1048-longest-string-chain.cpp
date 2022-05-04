class Solution {
    
private:
    
    bool compare(const string& a, const string& b){ // b is greater
        int n = a.size();
        int m = b.size();
        
        if(m-n!=1)
            return false;
        
        
       int i = 0 , j = 0;
        
        while(j<m){
            if(a[i] == b[j]) i++ , j++;
            else j++;
        }
        
        return i == a.size() and j == b.size();
        
    }
public:
    int longestStrChain(vector<string>& words) {
        
        const int n = words.size();
        
        sort(begin(words),end(words) , [](string& a , string& b) -> bool {
            return a.size() < b.size();
        });
        
        int ans = 1;
        vector<int> dp(n , 1);
        
        for(int i = 1;i<n;i++)
            for(int j = i-1;j>=0;j--)
                if(compare(words[j],words[i]) and dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    ans = max(ans , dp[i]);
                }
        
        for(string e:words) cout<<e<<" ";
        
        return ans;
        
    }
};
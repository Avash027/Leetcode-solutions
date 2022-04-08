class Solution {
private:
    bool isPossible(string&s ,int k, char c, int len){
        int cnt = 0;
        bool ok = 0;
        
        for(int i = 0;i<len;i++)
            cnt+=(s[i]!=c);
        
        ok|=(cnt<=k);
        
        if(ok) return true;
        
        for(int i = len;i<s.size();i++){
            cnt-=(s[i-len]!=c);
            cnt+=(s[i]!=c);
            
            ok|=(cnt<=k);
            
            if(ok) return true;
        }
        
        return false;
    }
    
    int maxLen(string s,int k,char c){
        int lo = 0 , hi = s.size();
        int ans = 0;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(isPossible(s,k,c,mid)) ans = mid , lo = mid+1;
            else hi = mid-1;
        }
        return ans;
    }
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        
        for(char c='A';c<='Z';c++)
            ans = max(ans , maxLen(s,k,c));
        
        return ans;
    }
};
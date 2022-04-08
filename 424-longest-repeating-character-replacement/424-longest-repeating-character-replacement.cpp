class Solution {
private:
    int maxLen(string s,int k,char c){
        int ans = 0,cnt = 0;
        int lo = 0 , hi = 0;
        
        while(hi<(int)s.size()){
            cnt+=(s[hi++]!=c);
            
            while(cnt>k)
                cnt-=(s[lo++]!=c);
            
            ans = max(ans , hi-lo);
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
class Solution {
private:
    int ind;
    
    bool compare(unordered_map<char,int>& freq,
                    unordered_map<char,int>& freq1
                    ){
        
        
        
        for(char c='A';c<='Z';c++){
            if(freq[c]>freq1[c]) return false;
        }
        
        for(char c='a';c<='z';c++){
            if(freq[c]>freq1[c]) return false;
        }
        return true;
    }
    
 
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq,freq1;
        
        for(char&c:t) freq[c]++;
        
        int lo = 0 , hi = 0;
        int ans = INT_MAX , ind = -1;
        
        while(hi<s.size()){
            freq1[s[hi++]]++;    
            
            while(compare(freq,freq1) and lo<hi){
                if(ans>hi-lo) ans = hi-lo , ind = lo;
                freq1[s[lo++]]--;
            }
        }
        
        if(ind == -1) return "";
        return s.substr(ind,ans);
    }
};
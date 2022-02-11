class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        if(n>m) return false;
        
        vector<int> freq(26,0),freq1(26,0);
        
        for(char c:s1) freq[c-'a']++;
        
        for(int i = 0;i<n;i++)
            freq1[s2[i]-'a']++;
        
        if(freq == freq1) return true;
        
        for(int i = n;i<m;i++){
            freq1[s2[i-n]-'a']--;
            freq1[s2[i]-'a']++;
            
            if(freq == freq1) return true;
        }
        
        return false;
    }
};
bool operator ==(const vector<int>&a , const vector<int>&b){
    bool ok =1;
    for(int i = 0;i<26;i++) ok&=(a[i]==b[i]);
    return ok;
}

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n1 = s.size();
        const int n2 = p.size();
        
        if(n1<n2) return {};
        
        
        vector<int> ans , freq(26 , 0),freq1(26,0);
        int cnt = 0;
        
        for(const char&c:p) freq[c-'a']++;
        
        for(int i = 0;i<n2;i++) freq1[s[i]-'a']++;
        
        if(freq1 == freq) ans.push_back(0);
        
        for(int i = n2;i<n1;i++)
        {
            freq1[s[i-n2]-'a']--;
            freq1[s[i]-'a']++;
            
            if(freq == freq1) ans.push_back(i-n2+1);
        }
        
        return ans;
        
    }
};
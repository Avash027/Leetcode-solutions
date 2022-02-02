class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n1 = s.size();
        const int n2 = p.size();
        
        if(n1<n2) return {};
        
        
        vector<int> ans;
        unordered_map<char,int> freq;
        int cnt = 0;
        
        for(const char&c:p) freq[c]--;
        
        for(int i = 0;i<n2;i++) if(++freq[s[i]] == 0) freq.erase(s[i]);
        
        if(freq.empty()) ans.push_back(0);
        
        for(int i = n2;i<n1;i++)
        {
            if(--freq[s[i-n2]] == 0) freq.erase(s[i-n2]);
            if(++freq[s[i]] == 0) freq.erase(s[i]);
            
            if(freq.empty()) ans.push_back(i-n2+1);
        }
        
        return ans;
        
    }
};
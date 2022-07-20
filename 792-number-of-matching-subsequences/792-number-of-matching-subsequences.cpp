class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        int ans = 0;
        vector<vector<int>> mappings(26);
        for(int i = 0; i < size(s); i++) mappings[s[i] - 'a'].push_back(i);
        for(auto& word : words) {
            bool found = true;
            for(int i = 0, prev = -1; found && i < size(word); i++) {
                auto& v = mappings[word[i]-'a'];
                auto it = upper_bound(begin(v), end(v), prev);   
                if(it == end(v)) found = false;                 
                else prev = *it;                                 
            }
            ans += found;
        }
        return ans;
    }
};
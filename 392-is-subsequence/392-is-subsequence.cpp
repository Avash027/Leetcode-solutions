class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int n = s.size();
        const int m = t.size();
        int i = 0 , j = 0;
        
        while(i<n and j<m){
            if(s[i] == t[j]) i++,j++;
            else j++;
        }
        
        return i == n;
    }
};
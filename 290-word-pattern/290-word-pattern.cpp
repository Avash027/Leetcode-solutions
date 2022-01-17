class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream scin(s);
        map<string,int> umpp1;
        map<char,int> umpp2;
        
        string x;
        int i = 0;
        while(scin>>x){
            if(i == pattern.size() or umpp1[x]!=umpp2[pattern[i]])
                return false;
        
            umpp2[pattern[i]] = umpp1[x] = i+1;
            i++;
        }
        
        return i==pattern.size();
    }
};
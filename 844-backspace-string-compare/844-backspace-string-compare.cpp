

class Solution {
private:

    string makeString(string s){
        string s1="";
        for(int i = 0;i<s.size();i++){
            if(s[i]!='#') s1.push_back(s[i]);
            else if(s1.size()!=0) s1.pop_back();
        }
        
        return s1;
    }
    
public:
    bool backspaceCompare(string s, string t) {
        return makeString(s) == makeString(t);
    }
};
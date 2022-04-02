class Solution {
private:
    bool isPal(const string&s,int i,int j){
        while(++i<--j) if(s[i]!=s[j]) return false;
        return true;
    }
    
public:
    bool validPalindrome(string s) {

        
        for(int i = 0,j = s.size()-1;i<j;i++,j--){
            if(s[i]!=s[j]) return isPal(s,i,j+1) or isPal(s,i-1,j); 
        }
        
        return true;
    }
};
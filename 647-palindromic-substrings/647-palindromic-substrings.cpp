class Solution {
private:
    int count(string&s , int i , int j){
        int cnt = 0;
        
        while(i>=0 and j<s.size() and s[i]==s[j]) i--,j++ , cnt++;
        
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        
        
        for(int i = 0;i<s.size();i++){
            ans+=count(s,i,i);
            ans+=count(s,i,i+1);
        }
        
        return ans;
    }
};
class Solution {
private:
    int maxChars(const string&s, char c,int k) {
        int len = 0;
        const int N = s.size();
        int l = 0, r = 0;
        
        int cntOtherans = 0;
        
        while(r<N){
            cntOtherans += (s[r++] != c);
            
            while(cntOtherans > k)
                cntOtherans -= (s[l++] != c);
            
            len = max(len, r-l);
        }
        
        return len;
        
        
        
    }
public:
    int maxConsecutiveAnswers(string s, int k) {
        return max(maxChars(s,'T',k), maxChars(s,'F',k));
    }
};
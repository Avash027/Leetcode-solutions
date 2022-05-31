class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int N = s.size();
        
        if(N<k) return false;
        int comb = 1<<k;
        int len = comb - 1;
        
        vector<bool> needs(comb ,false);
        int hash = 0;
        
        for(int i = 0;i<N;i++){
            hash = ((hash << 1)& len) | (s[i]-'0');
            if(i-k+1>=0 and !needs[hash]){
                needs[hash] = true;
                comb--;
                
                if(comb == 0) return true;
            }
        }
        
        return false;
    }
};
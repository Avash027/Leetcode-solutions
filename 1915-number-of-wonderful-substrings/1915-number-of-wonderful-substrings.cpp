class Solution {
public:
    long long wonderfulSubstrings(string word) {
        const int N = word.size();
        unordered_map<int,int> maskCnt;
        
        
        long long ans = 0;
        int mask = 0;
        maskCnt[0] = 1;
 
        for(int i = 0;i<N;i++){
            
            mask ^= (1<<(word[i]-'a'));
          
            ans+=maskCnt[mask];
            
            for(int i = 0;i<10;i++)
                ans += maskCnt[mask^(1<<i)];
            
              maskCnt[mask]++;
            
        }
        
        return ans;
        
    }
};
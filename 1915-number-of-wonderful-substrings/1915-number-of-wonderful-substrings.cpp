class Solution {
public:
    long long wonderfulSubstrings(string word) {
        const int N = word.size();
        unordered_map<int,int> maskCnt;
        vector<vector<int>> pre(N , vector<int>(10 , 0));
        
        
        long long ans = 0;
        
        maskCnt[0] = 1;
 
        for(int i = 0;i<N;i++){
            
            int mask = 0;
            
            for(char c = 'a';c<='j';c++){
                pre[i][c-'a'] += (i > 0 ? pre[i-1][c-'a'] : 0) + (c == word[i]);
            
                if(pre[i][c-'a']&1)
                    mask += (1<<(c-'a'));
            
            }

          
            ans+=maskCnt[mask];
            
            for(int i = 0;i<10;i++)
                ans += maskCnt[mask^(1<<i)];
            
              maskCnt[mask]++;
            
        }
        
        return ans;
        
    }
};
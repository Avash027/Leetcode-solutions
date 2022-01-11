class Solution {
private:
    map<string,bool> makeDict(const vector<string>& arr){
        map<string , bool> dict;
        
        for(const string s:arr)
            dict[s] = true;
        
        return dict;
    }
    
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        const int N = s.size();
        
        map<string,bool> dict = makeDict(wordDict);
        vector<bool> dp(N , false);
        
            
        for(int i = 0;i<N;i++)
        {
            
            string curWord = s.substr(0 , i+1);
            dp[i] = dict[curWord];
            
            for(int j = i-1;j>=0;j--)
            {
                if(!dp[j]) continue;
                
                string curWord = s.substr(j+1 , i - (j+1)+1);
                
                if(dict[curWord])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[N-1];
            
        
    }
};
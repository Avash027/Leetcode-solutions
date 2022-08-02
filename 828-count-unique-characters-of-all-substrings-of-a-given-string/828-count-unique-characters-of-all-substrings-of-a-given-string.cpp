class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> index[26];
        const int N = s.size();
        
        for(int i = 0;i<N;i++)
            index[s[i]-'A'].push_back(i);
        
        for(int i = 0;i<26;i++){
            index[i].push_back(N);
            index[i].push_back(-1);
            sort(begin(index[i]),end(index[i]));
        }
        
        int ans = 0;
        
        
        for(int i = 0;i<26;i++)
            for(int j = 1;j<index[i].size()-1;j++){
                int left = index[i][j] - index[i][j-1];
                int right = index[i][j+1] - index[i][j];
                
                ans += left * right;
            }
            
        return ans;
        
    }
};
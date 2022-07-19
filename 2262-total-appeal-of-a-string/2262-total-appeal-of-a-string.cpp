class Solution {
public:
    long long appealSum(string s) {
        vector<int> prev(26,0);
        const int N = s.size();
        long long ans = 0,cur=0;
        
        
        for(int i = 0;i<N;i++){
            cur += i+1 - prev[s[i]-'a'];
            ans += cur;
            prev[s[i]-'a'] = i+1;
            
        }
        
        return ans;
    }
};
class Solution {
private:
    void findPalindrome(string s , vector<int>& dp){
        int n = s.size();
        for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(dp[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        dp[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
}
    }
public:
    long long maxProduct(string s) {
        const int N = s.size();
        queue<pair<int,int>> q,q1;
        vector<int> dp(N , 0);
        
        findPalindrome(s,dp);
        long long ans = 0LL , l = 0;
        vector<int> r2l(N);
        
        for(int i = N-1;i>=0;i--){
            while(!q.empty() and q.front().first-q.front().second>i-1)
                q.pop();
            
            r2l[i] = 1 + (q.empty()?0:2*(q.front().first - i));
            q.push({i,dp[i]});
        }
        
        for(int i = 0;i<N-1;i++){
              while(!q1.empty() and q1.front().first+q1.front().second<i+1)
                q1.pop();
            
            l = max(l , 1LL + (q1.empty()?0:2*(i-q1.front().first)));
            ans = max(ans , 1LL*l*r2l[i+1]);
            q1.push({i,dp[i]});
        }
        
    
        
        return ans;
        
    }
};
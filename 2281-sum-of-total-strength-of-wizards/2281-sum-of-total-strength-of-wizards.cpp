// https://leetcode.com/problems/sum-of-total-strength-of-wizards/discuss/2062017/C%2B%2B-prefix-%2B-monotonic-stack-O(N)-solution-with-thought-process

constexpr long long MOD = 1000000007;

class Solution {
public:
    int totalStrength(vector<int>& arr) {
        const int n = arr.size();
        vector<long long> nxt(n,n) , prev(n,-1);
        vector<long long> pre(n+1 , 0) , pre1(n+2 , 0);
        stack<long long> st;
        
        for(int i = 0;i<n;i++)
            pre[i+1] = (pre[i] + arr[i])%MOD;
        
        for(int i= 0;i<=n;i++)
            pre1[i+1] = (pre1[i] + pre[i])%MOD;
        
        for(int i = 0;i<n;i++){
            while(!st.empty() and arr[i] <= arr[st.top()]){
                st.pop();
            }
            
            prev[i] = st.empty()?-1:st.top();
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n-1;i>=0;i--){
            while(!st.empty() and arr[i]<arr[st.top()]){
                st.pop();
            }
            nxt[i] = st.empty() ? n:st.top();
            st.push(i);
        }
        
        long long ans = 0;
        
        for(int i = 0;i<n;i++){
            long long pos = ((pre1[nxt[i]+1] - pre1[i+1])%MOD * (i - prev[i])%MOD)%MOD;
            long long neg = ((pre1[i+1] - pre1[prev[i]+1])%MOD *(nxt[i]-i)%MOD)%MOD;
            
            ans = (ans + ((pos - neg +MOD)%MOD*arr[i]%MOD)%MOD + MOD)%MOD;
        }
        ans%=MOD;
        
        return (int)ans;
        
        
    }
};
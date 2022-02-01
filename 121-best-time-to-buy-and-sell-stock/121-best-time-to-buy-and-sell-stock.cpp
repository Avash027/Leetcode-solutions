class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int pre = 1e5;
        int ans = 0;
        vector<int> sufMax(n,-1);
        
        
        for(int i = n-1;i>=0;i--){
            sufMax[i] = prices[i];
            if(i!=n-1) sufMax[i] = max(sufMax[i+1] , sufMax[i]);
        }
        
        for(int i = 0;i<n;i++)
        {
            pre = min(pre , prices[i]);
            ans = max(ans , sufMax[i] - pre);
        }
        
        return ans;
    }
};
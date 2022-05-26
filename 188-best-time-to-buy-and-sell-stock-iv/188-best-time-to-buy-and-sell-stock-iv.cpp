class Solution {
private:
        
    vector<vector<vector<int>>> dp;
    
    int profit(vector<int>& prices,int ind, bool canBuy , int numOfTr){
        if(ind == prices.size() || numOfTr == 0) 
            return 0;
        
        int p = 0;
        
        if(dp[ind][canBuy][numOfTr]!=-1) return dp[ind][canBuy][numOfTr];
        
        if(canBuy)
            p = max(-prices[ind] + profit(prices,ind+1,false,numOfTr) , 
                            0 + profit(prices,ind+1,true,numOfTr)
                        );
        else
            p = max(prices[ind] + profit(prices,ind+1,true,numOfTr-1) , 
                            0 + profit(prices,ind+1,false,numOfTr)
                        );
        
        return dp[ind][canBuy][numOfTr] = p;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
         const int n = prices.size();
        
        dp.assign(n+1 , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
        
        return profit(prices,0,1,k);
    }
};
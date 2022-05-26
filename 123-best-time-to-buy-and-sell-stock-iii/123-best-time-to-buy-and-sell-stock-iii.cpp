class Solution {
private:

//     int profit(vector<int>& prices,int ind, bool canBuy , int numOfTr){
//         if(ind == prices.size() || numOfTr == 0) 
//             return 0;
        
//         int p = 0;
        
//         if(dp[ind][canBuy][numOfTr]!=-1) return dp[ind][canBuy][numOfTr];
        
//         if(canBuy)
//             p = max(-prices[ind] + profit(prices,ind+1,false,numOfTr) , 
//                             0 + profit(prices,ind+1,true,numOfTr)
//                         );
//         else
//             p = max(prices[ind] + profit(prices,ind+1,true,numOfTr-1) , 
//                             0 + profit(prices,ind+1,false,numOfTr)
//                         );
        
    //     return dp[ind][canBuy][numOfTr] = p;
    // }
    
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        
        int dp[n+1][2][3];
        
        for(int i = 0;i<n;i++)
            for(int j = 0;j<2;j++)
                dp[i][j][0] = 0; // i is ind and j is canBuy and 0 in numOfTr
        
        for(int i = 0;i<2;i++)
            for(int j = 0;j<3;j++)
                dp[n][i][j] = 0;
        
        for(int i = n-1;i>=0;i--)
            for(int canBuy = 0;canBuy<2;canBuy++)
                for(int numOfTr = 1;numOfTr <= 2;numOfTr++){
                    if(canBuy)
                        dp[i][canBuy][numOfTr] = max(-prices[i] + dp[i+1][0][numOfTr], dp[i+1][1][numOfTr]);
                     else 
                        dp[i][canBuy][numOfTr] = max(prices[i] + dp[i+1][1][numOfTr-1], dp[i+1][0][numOfTr]);
                }
        
        return dp[0][1][2];
    }
};
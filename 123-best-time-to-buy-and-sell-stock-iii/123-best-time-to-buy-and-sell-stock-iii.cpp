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
        
        vector<vector<int>> cur(2 , vector<int>(3,0));
        vector<vector<int>> nxt(2 , vector<int>(3,0));
       
        
        for(int i = n-1;i>=0;i--){
            for(int canBuy = 0;canBuy<2;canBuy++){
                for(int numOfTr = 1;numOfTr <= 2;numOfTr++){
                    if(canBuy)
                        cur[canBuy][numOfTr] = max(-prices[i] + nxt[0][numOfTr], nxt[1][numOfTr]);
                     else 
                        cur[canBuy][numOfTr] = max(prices[i] + nxt[1][numOfTr-1], nxt[0][numOfTr]);
                }
            }
            
            nxt = cur;
        }
        
        return nxt[1][2];
    }
};
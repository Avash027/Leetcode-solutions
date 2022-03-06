constexpr long long MOD = 1e9+7;

class Solution {
public:
    int countOrders(int n) {
        
        long long last =1;    
        long long ans = last;
        
        for(int i = 2;i<=n;i++){
            long long space = 2*i-1;
            long long arrangeCurrentDelivery = (space*(space+1))/2;
            
            ans = (last*arrangeCurrentDelivery)%MOD;
            last = ans;
        }
        
        return (int)ans;
    }
};
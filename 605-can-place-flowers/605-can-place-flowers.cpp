class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        
        for(int i = 0;i<sz and n;i++){
            if(flowerbed[i]==1) continue;
            
            if(i+1==sz and i-1<0){
                 n-- , flowerbed[i]=1;
            }
            else if(i+1==sz){
                if(flowerbed[i-1] == 0)
                    n-- , flowerbed[i] = 1;
            }
            else if(i-1<0){
                if(flowerbed[i+1]==0)
                    n-- , flowerbed[i]=1;
            }
            else if (flowerbed[i+1] == 0 and flowerbed[i-1] == 0){
                n--, flowerbed[i]=1;
            }
        }
        
        
        return n<=0;
    }
};
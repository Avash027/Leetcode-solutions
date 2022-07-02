class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        long long ans = 0;
        
        for(int i = 29;i>=0;i--){
           
            long long cnt1 = 0 , cnt2 = 0;
            for(int&e:arr1){
                if((1<<i)&e)
                    cnt1++;
            }
            
            
            for(int&e:arr2){
                if((1<<i)&e)
                    cnt2++;
            }

            
            cnt1*=cnt2;
            
            if(cnt1&1)
                ans+=1<<i;
        }
        
        return ans;
    }
};
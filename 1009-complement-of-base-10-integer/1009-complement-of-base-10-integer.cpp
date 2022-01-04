class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int ans = 0,ind = 0;;
        
        while(n){
            ans+=(!(n&1)) * (1<<ind);
            n>>=1;
            ind++;
        }
        return ans;
    }
};
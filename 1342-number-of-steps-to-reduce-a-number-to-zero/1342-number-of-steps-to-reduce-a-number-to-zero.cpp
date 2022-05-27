class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0;
        int cnt = 0;
        while(num) {
            cnt+=1 + (num&1);
            num>>=1;
        }
        
        cnt--;
        
        return cnt;
    }
};
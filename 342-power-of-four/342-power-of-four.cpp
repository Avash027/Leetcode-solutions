class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1 and n%4 == 0) n>>=2;
        return n == 1;
        
    }
};
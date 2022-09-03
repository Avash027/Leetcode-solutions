class Solution {
private:
    vector<int> ans;
    
    void calculate(int num,  int k, int n){
        if(num!=0 and floor(log10(num)+1) == n){
            ans.push_back(num);
            return;
        }
        
        int lastDigit = num%10;
        
        for(int i = 0;i<=9;i++)
            if(abs(lastDigit - i)==k)
                calculate((num*10)+i , k , n);
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        //This is to handle leading zero case
        for(int i = 1;i<=9;i++)
            calculate(i,k,n);
        
        return ans;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int n = a.size(),m = b.size(),carry = 0;
        n--,m--;
        
        
        while(n>=0 or m>=0 or carry){
            int v1 = n>=0?a[n]-'0':0;
            int v2 = m>=0?b[m]-'0':0;
            
            ans+=char('0' + (v1+v2+carry)%2);
            carry = (carry+v1+v2)/2;
            
            n--,m--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
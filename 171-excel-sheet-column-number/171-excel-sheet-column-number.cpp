class Solution {
public:
    int titleToNumber(string columnTitle) {
        const int n  = columnTitle.size();
        int ans = 0;
        long long base= 1;
        
        for(int i = n-1;i>=0;i--){
            ans+=base*(columnTitle[i]-'A'+1);
            base*=26;
        }
        
        return ans;
    }
};
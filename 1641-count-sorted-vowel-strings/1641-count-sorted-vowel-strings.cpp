class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> ans{5,4,3,2,1};
        
        for(int i = 2;i<=n;i++){
            vector<int> newAns(5 ,0);
            newAns[4] = ans[4];
            
            for(int j = 3;j>=0;j--)
                newAns[j] = newAns[j+1] + ans[j];
            
            ans = newAns;
        }
        
        return ans[0];
    }
};
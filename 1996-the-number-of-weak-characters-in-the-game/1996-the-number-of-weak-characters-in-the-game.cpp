bool comp(vector<int>&a , vector<int>&b){
    return (a[0] == b[0])? a[1]>b[1]:a[0]<b[0];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(begin(p),end(p),comp);
        int ans = 0;
        const int N = p.size();
        
        int mx = -1;
        
        for(int i = N-1;i>=0;i--){
            if(p[i][1]<mx)
                ans++;
            
            mx = max(mx,p[i][1]);
        }
        return ans;
        
    }
};
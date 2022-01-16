class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int cnt = 0, ans = 0, n=seats.size();
        bool p = 0;
        
        for(int i = 0;i<n;i++){
            if(seats[i]==0) cnt++;
            else {
                if(!p) ans = max(ans , cnt);
                else ans = max(ans,(cnt+1)/2);
                p=1;
                cnt = 0;
            }
            
        }
        
        ans = max(ans ,cnt);
        return ans;
    }
};
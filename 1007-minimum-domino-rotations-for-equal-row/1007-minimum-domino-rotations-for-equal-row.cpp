constexpr int INF = 1e8;

class Solution {
private:
    int minValue(vector<int>&x , vector<int>&y , int val){
        int ans = 0;
        
        for(int i = 0;i<x.size();i++)
        {
            if(x[i] == val) continue;
            else if(y[i] == val) ans++;
            else return INF;
        }
        
        return ans;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int ans = INF;
        
        for(int num=1;num<=6;num++)    
            ans = min({ans , minValue(tops,bottoms,num), minValue(bottoms,tops,num)});    
        
        if(ans == INF) ans = -1;
        
        return ans;
    }
};
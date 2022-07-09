class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        unordered_map<int,int> limits;
        const int N = s.size();
        int can_reach = 0;
        
        
        for(int i = 0;i<N;i++){
            can_reach+=limits[i];
            
            if((s[i] == '0' and can_reach) or i == 0){
                limits[i + minJump] += 1;
                limits[i + maxJump+1] += -1;
            }
        }
        
        return can_reach and s.back() != '1';
        
        
    }
};
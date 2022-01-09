class Solution {
public:
    bool isRobotBounded(string instructions) {
        string s;
        for(int i = 0;i<4;i++) s+=instructions;
        const int N = s.size();
        
        int x = 0 ,  y = 0 , dir = 0;
        
        for(int i = 0;i<N;i++){
            if(s[i]=='L') dir= (dir + 1)%4;
            else if(s[i]=='R') dir = (dir-1 + 4)%4;
            else{
                if(dir==0) y++;
                else if(dir==1) x++;
                else if(dir==2) y--;
                else x--;
            }
            
        }
        
        return x==0 and y==0;
        
    }
};
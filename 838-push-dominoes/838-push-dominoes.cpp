constexpr int INF = 1e7;

class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.size();
        vector<int> leftFalls(N , INF);
        int rightFalls = INF;
        
        string ans;

        
        for(int i = N-1;i>=0;i--){
            if(dominoes[i] == 'L')
                leftFalls[i] = 0;
            else if (dominoes[i] == 'R')
                leftFalls[i] = INF;
            else if(i!=N-1)
                leftFalls[i] = min(leftFalls[i+1]+1,leftFalls[i]);
        }
        
        for(int i = 0;i<N;i++){
            if(dominoes[i] == 'R')
                rightFalls = 0;
            else if(dominoes[i] == 'L')
                rightFalls = INF;
            else if(i!=0)
                rightFalls = min(rightFalls+1, INF);
            

            
            if(rightFalls < leftFalls[i])
                ans.push_back('R');
            else if(rightFalls > leftFalls[i])
                ans.push_back('L');
            else
                ans.push_back('.');
            
        }
        
        
        return ans;
        
    }
};
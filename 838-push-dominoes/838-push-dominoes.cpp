constexpr int INF = 1e7;

class Solution {
public:
    string pushDominoes(string dominoes) {
        const int N = dominoes.size();
        // leftFalls[i] denotes when the i+1 th tile falls on the ith tile
        // If it never falls then it will be INF
        vector<int> leftFalls(N , INF);
        //Same for rightFalls
        int rightFalls = INF;
        
        string ans;

        
        for(int i = N-1;i>=0;i--){
            // If the ith block is L then it falls on the left side at time 0
            if(dominoes[i] == 'L')
                leftFalls[i] = 0;
            // If we encounter an R, then our left falling dominoes stops and 
            //it will never fall on the ith  dominoe
            else if (dominoes[i] == 'R')
                leftFalls[i] = INF;
            // If the i+1th domino fell from left at x then ith dominoe will fall 
            // at x+1
            //But if it is not falling it will stay INF
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
            

            //If the right falls before left
            if(rightFalls < leftFalls[i])
                ans.push_back('R');
            //If the left falls before right
            else if(rightFalls > leftFalls[i])
                ans.push_back('L');
            //If both fall at the same time
            else
                ans.push_back('.');
            
        }
        
        
        return ans;
        
    }
};
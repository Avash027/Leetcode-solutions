class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        int ans = 0;
        
        for(int i = 0;i<N;i++)
            for(int j = 0;j<M;j++){
                if(matrix[i][j] == 0) continue;
                
                
                if(i>0 and j>0)
                    matrix[i][j] += min({matrix[i-1][j] , matrix[i][j-1], matrix[i-1][j-1]});
                
                ans += matrix[i][j];
                
            }
        
        return ans;
    }
};
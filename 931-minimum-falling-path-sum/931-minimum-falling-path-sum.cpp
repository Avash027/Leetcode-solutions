constexpr int INF = 1000000;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        int left,top,right;
        
        for(int i = 1;i<n;i++)
            for(int j = 0;j<n;j++){
                left = right = top = INF;
                
                if(j-1>=0) left = matrix[i-1][j-1];
                top = matrix[i-1][j];
                if(j+1<n) right = matrix[i-1][j+1];
                
                matrix[i][j]+= min({left,right,top});
            }
        
        
        return *min_element(begin(matrix.back()) ,end(matrix.back()));
        
    }
};
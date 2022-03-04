class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> arr(102 , vector<double>(102,0));
        
        arr[0][0] = poured;
        
        for(int i = 0;i<=query_row;i++)
            for(int j = 0;j<=i;j++){
                if(arr[i][j]<1.0) continue;
                double excess = (arr[i][j]-1.0)/2.0;
                
                arr[i+1][j]+=excess;
                arr[i+1][j+1]+=excess;
            }
        
        
        return min(1.0 , arr[query_row][query_glass]);
    }
};

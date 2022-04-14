constexpr int INF = 1000000;

class Solution {

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev(1 , triangle[0][0]);
        const int n = triangle.size();
        
        for(int i = 1;i<n;i++){
            vector<int> cur(prev.size()+1 , INF);
            
            for(int j = 0;j<triangle[i].size();j++){
                if(j<prev.size()) cur[j] = triangle[i][j] +  prev[j];
                if(j-1>=0) cur[j] = min(cur[j] , triangle[i][j] +  prev[j-1]);
            }
            
            prev = cur;
                
        }
        
        return *min_element(begin(prev),end(prev));
    
    }
};
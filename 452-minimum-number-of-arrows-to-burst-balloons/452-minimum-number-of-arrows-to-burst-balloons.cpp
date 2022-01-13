
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int arrows = 1;
        long long ub = 1e11;
        
        for(const auto&point:points){
            if((long long)point[0]>ub)
                arrows++ , ub = point[1];
            else ub = min(ub , (long long)point[1]);
        }
        
        return arrows;
    }
};
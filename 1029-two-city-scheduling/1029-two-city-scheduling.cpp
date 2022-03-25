class Solution {
public:
    static bool comp1(vector<int>&x , vector<int>&y){
        return x[0] - x[1] <y[0] - y[1];
    }
    
    int minValue(vector<vector<int>>& costs){
        int n = costs.size();
        sort(begin(costs),end(costs) , comp1);
        int cost = 0;
        
        for(int i = 0;i<n;i++)
            cost+=(i<n/2?costs[i][0]:costs[i][1]);
        
        return cost;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        int ans = minValue(costs);
        
        
        
        return ans;
    }
};
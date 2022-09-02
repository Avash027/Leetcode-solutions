// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        const int N = points.size();
        // yj + yi + |xi - xj|
        // (yi - xi) + (xj + yj)   (xj > xi) 

        
        // store the elements in the order [yi - xi , xi]
        //In monotonic dqueue
        deque<pair<int,int>> dq;
        
        
        dq.push_back(
        make_pair(points[0][1] - points[0][0] , points[0][0])
        );
        
        int ans = INT_MIN;
        
        for(int i = 1;i<N;i++){
            auto e = points[i];
            
            while(!dq.empty() and abs(e[0] - dq.front().second) > k)
                dq.pop_front();
            
            if(!dq.empty()) 
                ans = max(ans , e[0] + e[1] + dq.front().first);
            
            while(!dq.empty() and e[1] - e[0] > dq.back().first)
                dq.pop_back();
            
            dq.push_back({e[1] - e[0] , e[0]});
            
        }
        
        return ans;
        
    }
};
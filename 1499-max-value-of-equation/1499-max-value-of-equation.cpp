// Time Complexity: O(NlogN)
// Space Complexity: O(N)

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        const int N = points.size();
        // yj + yi + |xi - xj|
        // (yi - xi) + (xj + yj)   (xj > xi) 

        
        // store the elements in the order [yi - xi , xi]
        priority_queue<pair<int,int>> pq;
        
        pq.push(
        make_pair(points[0][1] - points[0][0] , points[0][0])
        );
        
        int ans = INT_MIN;
        
        for(int i = 1;i<N;i++){
            auto e = points[i];
            
            while(!pq.empty() and abs(e[0] - pq.top().second) > k)
                pq.pop();
            
            if(!pq.empty()) 
                ans = max(ans , e[0] + e[1] + pq.top().first);
            
            pq.push(make_pair(e[1] - e[0] , e[0]));
        }
        
        return ans;
        
    }
};
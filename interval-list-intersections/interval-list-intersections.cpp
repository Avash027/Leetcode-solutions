class Solution {
private:
    
 
    
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        const int N = firstList.size();
        const int M = secondList.size();
        
        vector<vector<int>> ans;
        
        int i = 0 , j = 0;
        
        while(i<N and j<M)
        {
            
            int front = max(firstList[i][0], secondList[j][0]); 
            int back = min(firstList[i][1], secondList[j][1]);
            
            if(back>=front)
                ans.push_back({front,back});
            
             if(firstList[i][1] < secondList[j][1]) i++;
            else  j++;
        }
      
        
        return ans;
        
        
    }
};
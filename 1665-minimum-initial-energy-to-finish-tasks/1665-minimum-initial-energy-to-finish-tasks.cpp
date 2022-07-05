class Solution {
public:
    
    static bool comp(vector<int>&a , vector<int>& b){
        return a[1] - a[0] < b[1] - b[0];
    }
    

    
    int minimumEffort(vector<vector<int>>& tasks) {
        

        sort(begin(tasks),end(tasks),comp);
        int ans = 0;
        
        for(auto&e:tasks){
            //We need e[0] to complete the tasks 
            //or minimum energy to approach the tasks
            ans = max(ans + e[0] , e[1]);
        }
        
        return ans;
        
       
        
        
    }
};
bool comp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
    
        if(arr.size()==0) return 0;
        sort(begin(arr) , end(arr),comp);
        
        int back= arr[0][1] , cnt = 1;
        
        for(int i =1;i<arr.size();i++)
        {
            if(arr[i][0]>=back)  back = arr[i][1],cnt++;
           
        }
        
        return arr.size()-cnt;
        
    
    }
};
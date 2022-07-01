class Solution {
public:
    static bool comp(const vector<int>&a , const vector<int>&b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {
        sort(begin(arr),end(arr),comp);
        
        int ans = 0;
        
        for(auto& box:arr){
            int qt = min(box[0],truckSize);
            int units = box[1];
            
            ans+= qt*units;
            truckSize -= qt;
            
            if(truckSize == 0)
                break;
        }
        
        return ans;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int arr[1010] = {0};
        
        for(auto&e:trips){
            arr[e[1]]+=e[0];
            arr[e[2]]-=e[0];
        }
        
        for(int i= 0;i<1010;i++){
            if(i!=0) arr[i]+=arr[i-1];
            if(arr[i]>capacity) return false;
        }
        
        return true;
        
        
        
    }
};
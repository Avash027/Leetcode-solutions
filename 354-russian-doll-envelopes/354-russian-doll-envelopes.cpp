bool comp(vector<int>& a , vector<int>& b){
    if(a[0] == b[0]) return a[1]>b[1];
    return a[0]<b[0];
}



class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        sort(begin(arr),end(arr),comp);
        
        
        vector<int> lis;
        lis.push_back(arr[0][1]);
        
        for(int i = 1;i<arr.size();i++){
            if(arr[i][1]>lis.back()) lis.push_back(arr[i][1]);
            else{
                auto itr = lower_bound(begin(lis),end(lis),arr[i][1]);
                *itr = arr[i][1];
            }
        }
        
        return lis.size();
        
    }
};
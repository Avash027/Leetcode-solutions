class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(begin(arr),end(arr));
        const int n = arr.size();
        
        int i = 0 , j = n-1 , ans = 0;
        
        while(i<=j){
            if(arr[i] + arr[j]>limit)
                j-- , ans++;
            else
                j-- , i++ , ans++;
        }
        
        return ans;
        
    }
};
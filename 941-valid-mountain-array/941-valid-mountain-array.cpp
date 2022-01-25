class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        
        int i = 0;
        while(i<n-1 and arr[i]<arr[i+1]) i++;
        
        if(i ==0 or i == n-1) return false;
        
        while(i+1<n and arr[i]>arr[i+1]) i++;
        
        return i == n-1;
    }
};
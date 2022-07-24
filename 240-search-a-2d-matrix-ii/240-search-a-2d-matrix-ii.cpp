class Solution {
    private:
    
    
    bool findValue(const vector<int>&arr , int target){

        int lo = 0 , hi = (int)arr.size()-1;
        
        while(lo<=hi)
        {
            int mid = (lo + hi)>>1;
            if(arr[mid] == target) return true;
            if(target>arr[mid]) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
                ios::sync_with_stdio(0);
        for(int i = 0;i<(int)matrix.size();i++)
            if(findValue(matrix[i] , target)) return true;
        
        return false;
    }
};
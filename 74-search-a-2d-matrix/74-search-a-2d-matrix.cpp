class Solution {
private:
   
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int lo = 0;
        int hi = row* col -1;
        int ans = 0;
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int val = matrix[mid/col][mid%col];
            
            if(target == val) return true;
            else if(target<val) hi = mid-1;
            else lo = mid+1;
        }
        
        return false;
    }
};
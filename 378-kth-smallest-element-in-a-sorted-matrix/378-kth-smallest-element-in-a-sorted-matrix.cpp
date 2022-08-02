
class Solution {
    
private:

    int n;
    
    int cntLessOrEq(vector<vector<int>>& matrix , int val){
        int cnt = 0 , c = n-1;
        
        for(int r = 0;r<n;r++){
            while(c>=0 and matrix[r][c]>val) c--;
            cnt+=c+1;
        }
        
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
       
        int lo = matrix[0][0] , hi = matrix[n-1][n-1];
        int ans = -1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            if(cntLessOrEq(matrix,mid)>=k) ans = mid , hi = mid-1;
            else lo = mid+1;
            
        }
        
        return ans;
    }
};
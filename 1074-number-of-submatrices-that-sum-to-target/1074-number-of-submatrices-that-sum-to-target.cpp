class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        const int N = matrix.size();
        const int M = matrix[0].size();
        int ans = 0;
        
        for(int i = 0;i<N;i++)
            for(int j = 1;j<M;j++)
                matrix[i][j]+=matrix[i][j-1];
        
        unordered_map<int,int> cnt;
        for(int i = 0;i<M;i++)
            for(int j = i;j<M;j++){
                cnt.clear();
                cnt[0] = 1;
                int cur = 0;
                
                for(int k =0;k<N;k++){
                    cur += matrix[k][j] - (i>0?matrix[k][i-1]:0);
                    if(cnt.count(cur-target)) ans+= cnt[cur-target];
                    cnt[cur]++;
                }
            }
        
        return ans;
        
        
    }
};
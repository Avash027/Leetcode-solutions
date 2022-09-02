class Solution {
private:
    bool validate(int submask , vector<vector<int>>& arr , int N){
        
        
        for(int i = 0;i<N;i++){
            if(!(submask & (1<<i))) continue;
            
            for(int j = 0;j<N;j++){
                if(arr[i][j] == 2) continue;
                
                if(arr[i][j] == 0 and (submask & (1<<j))) // j is evil
                        return false;

                
                if(arr[i][j] == 1 and !(submask & (1<<j))) // j is good
                       return false;    
            }
        }
        
        return true;
        
    }
public:
    int maximumGood(vector<vector<int>>& statements) {
        const int N = statements.size();
        const int mask = (1<<N) - 1;
        
        int ans = 0;
        
        for(int submask = mask;submask;submask = (submask-1)&mask){
            if(validate(submask,statements,N)){
                ans = max(__builtin_popcount(submask),ans);
               
            }
        }
        
        return ans;
    }
};
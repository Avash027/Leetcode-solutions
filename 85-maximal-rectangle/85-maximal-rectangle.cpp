class Solution {
private:
    int maxArea(vector<int>&arr , int n){
         stack<int> st;
         int ans = 0;
         for(int i = 0;i<=n;i++){
             while(!st.empty() and (i == n || arr[st.top()] >= arr[i])){
                 int h = arr[st.top()];
                 st.pop();
                 int w = 0;
                 if(st.empty()) w = i;
                 else w = i-st.top()-1;
                 
                 
                 ans = max(ans , h*w);
             }
             st.push(i);
         }
         
         return ans;
     }
public:
    int maximalRectangle(vector<vector<char>>& arr) {
       
        const int n = arr.size();
        const int m = arr[0].size();
        
        vector<vector<int>> matrix(n , vector<int>(m,0));
        
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++) matrix[i][j] = arr[i][j]-'0';
        
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            ans = max(ans , maxArea(matrix[i] , m));
            
            if(i!=n-1)
                for(int j =0;j<m;j++)
                    if(matrix[i+1][j]!=0) matrix[i+1][j]+=matrix[i][j];
        }
    
        return ans;
    }
};
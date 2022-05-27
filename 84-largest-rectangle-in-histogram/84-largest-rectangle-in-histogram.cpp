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
    int largestRectangleArea(vector<int>& arr) {
        return maxArea(arr , arr.size());
    
    }
};
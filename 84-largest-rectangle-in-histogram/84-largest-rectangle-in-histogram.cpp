class Solution {
private:
        
    int maxHeight(vector<int>&arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nxt(n,n) , prev(n,-1);
        
        for(int i = 0;i<n;i++){
            while(!st.empty() and arr[i] < arr[st.top()]){
                nxt[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i = n-1;i>=0;i--){
            while(!st.empty() and arr[i]<arr[st.top()]){
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        int ans = 0;
        
                                                                                                             
        
        
        for(int i = 0;i<n;i++){
            int left = i - prev[i]-1;
            int right = nxt[i] - i-1;
            
            
            
            ans = max(ans , arr[i]*(left + right+1));
        }
        
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = maxHeight(heights);
        
        return ans;
    }
};
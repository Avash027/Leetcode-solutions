class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        vector<int> ans;
        
        const int n = nums.size();
        
        st.push(nums[0]);
        
        for(int i = 1; i < n; i++){
            if(__gcd((long long)nums[i] , st.top()) == 1)
                st.push((long long)nums[i]);
            else{
                long long k = nums[i];
                
                while(!st.empty() and __gcd(k , st.top())>1){
                    k = (k * st.top())/(__gcd(k , st.top()));
                    st.pop();
                }
                
                st.push(k);
            }
        }
        
        while(!st.empty()) ans.push_back(st.top()) ,st.pop();
        
        reverse(begin(ans), end(ans));
        
        return ans;
        
    }
};
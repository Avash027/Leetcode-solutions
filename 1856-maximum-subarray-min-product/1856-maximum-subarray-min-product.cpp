constexpr int MOD =1e9 + 7;

class Solution {
private:
    void next(vector<int>&nums , vector<long long>&right){
        stack<int> st;
        
        for(int i =1;i<nums.size();i++){
            while(!st.empty() and nums[i]<nums[st.top()])
                right[st.top()] = i-1 , st.pop();
            
            st.push(i);
        }
        
        while(!st.empty()) right[st.top()] = (int)nums.size()-1 , st.pop();
    }
    
    void prev(vector<int>&nums,vector<long long>&left){
        stack<int> st;
       
        
        for(int i =nums.size()-1;i>=0;i--){
            while(!st.empty() and nums[i]<nums[st.top()])
                left[st.top()] = i+1 , st.pop();
            st.push(i);
        }
        
        while(!st.empty()) left[st.top()] = 0 , st.pop();
    }
    
    void prefix(vector<int>&nums,vector<long long>&pref){
        pref[0] = nums[0];
        for(int i =1;i<nums.size();i++)
            pref[i] = nums[i] + pref[i-1];
    }
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int N = nums.size();
        long long ans = 0;
        
        vector<long long> left(N,0LL) , right(N,0LL),pref(N , 0LL);
        
        next(nums,right);
        prev(nums,left);
        prefix(nums,pref);
        
        for(int i = 0;i<N;i++){
            long long sum = pref[right[i]] - (left[i]>0?pref[left[i]-1]:0);
            ans = max(ans ,1LL*sum*nums[i]);
        }
        
        ans%=MOD;
        if(ans<0) ans+=MOD;
        return ans;
        
        
    }
};
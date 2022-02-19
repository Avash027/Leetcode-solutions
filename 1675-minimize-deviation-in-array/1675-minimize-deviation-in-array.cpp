class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        
        set<int> st;
        
        for(int&e:nums)
            st.insert((e&1)?e*2:e);
        
        int ans = *st.rbegin()-*st.begin();
        while(*st.rbegin()%2 == 0){
        
        if(*st.rbegin()%2 == 0) st.insert(*st.rbegin()/2);
        st.erase(prev(st.end()));
        ans = min(ans , *st.rbegin()-*st.begin());
        }
      
        
        return ans;
    }
};
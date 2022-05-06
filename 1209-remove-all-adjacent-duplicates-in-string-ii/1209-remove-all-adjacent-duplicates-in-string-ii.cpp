class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string ans;
        
        
        for(const char&c:s){
            if(st.size() == 0 or st.top().first!=c)
                st.push({c , 1});
            else if(st.top().first == c and st.top().second+1!=k)
                st.push({c , st.top().second+1});
            else
                while(!st.empty() and c == st.top().first)
                    st.pop();
        }
        
        while(!st.empty())
            ans.push_back(st.top().first), st.pop();
    
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};
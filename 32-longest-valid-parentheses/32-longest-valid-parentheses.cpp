class Solution {
public:
    int longestValidParentheses(string s) {
        int temp = 0,ans = 0;
        
        stack<int> st;
        
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                
                if(st.empty()) st.push(i);
                else{
                    if(s[st.top()]=='(')
                    {
                        st.pop();
                        ans = max(ans , (i - (st.empty()?-1:st.top())));
                    }
                    else st.push(i);
                }
            }
        }
        
        return ans;
    }
};
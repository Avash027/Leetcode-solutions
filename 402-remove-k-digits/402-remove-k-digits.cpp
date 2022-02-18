class Solution {
public:
    string removeKdigits(string num, int k) {
        const int len = num.size();
        stack<char> st;
        string ans;
        
        if(k == len) return "0";
    
        for(char c:num){
            while(!st.empty() and k and c<st.top()){
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        while(k>0) st.pop(),k--;
        
        while(!st.empty())
            ans.push_back(st.top()) , st.pop();
        
        reverse(begin(ans),end(ans));
        
        int i = 0;
        while(i<ans.size() and ans[i]=='0') i++;
        
        ans =  ans.substr(i);
        if(ans == "") ans="0";
        
        return ans;
    
    }
};
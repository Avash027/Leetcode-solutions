class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        
        for(const char&c:s){
            if(c ==')'){
                unordered_map<char,int> cnt;
                while(st.top()!='(')
                    cnt[st.top()]++ , st.pop();
                st.pop();
                
                char op = st.top();
                
                
                if(op == '&')
                    st.push(cnt['f']?'f':'t');
                else if(op == '|')
                    st.push(cnt['t']?'t':'f');
                else
                    st.push(cnt['t']?'f':'t');
                
            }
           else if(c!=',')
                st.push(c);
             
        }
        
        return st.top() == 't';
        
    }
};
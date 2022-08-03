class MyCalendar {
public:
    set<pair<int,int>> st;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       
        auto itr = st.upper_bound({start,end});
        if(itr!=st.end() and itr->first<end) return false;
        if(itr != st.begin() and (--itr)->second > start) return false;
        st.insert({start,end});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
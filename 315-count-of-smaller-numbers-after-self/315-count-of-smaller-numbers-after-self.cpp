struct SegTree{
  
    vector<int> t;
    int n = 30001;
    
    SegTree(){
        t.assign(4*n,0);
    }
    
   void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += ((new_val&1)?1:-1);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
        }
      
    }
    
    int query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
           + query(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        SegTree st;
        int n = 30001;
        int offset = 10000;
        
        for(int&e:nums) e+=offset;
        for(int&e:nums) st.update(1,0,n-1,e,1);
    
        vector<int> ans(nums.size() , 0);
        
        for(int i = 0;i<nums.size();i++){
            st.update(1,0,n-1,nums[i] , 0);
            ans[i] = st.query(1,0,n-1,0,nums[i]-1);
        }
        
        return ans;
        
    
    }
};
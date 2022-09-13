class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.size();
        vector<set<int>> ls(3);
        
        for(int i = 0;i<N;i++)
            ls[s[i]-'a'].insert(i);
        
        ls[0].insert(N+1);
        ls[1].insert(N+1);
        ls[2].insert(N+1);
        
        int ans = 0;
        
        for(int i = 0;i<N;i++){
            int ind_a = *ls[0].lower_bound(i);
            int ind_b = *ls[1].lower_bound(i);
            int ind_c = *ls[2].lower_bound(i);
            
            if(max({ind_a,ind_b,ind_c})>N)
                continue;
            
            ans += N - max({ind_a,ind_b,ind_c});
        }
        
        return ans;
        
        
    }
};
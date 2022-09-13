class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.size();
        vector<vector<int>> ls(3);
        
        for(int i = 0;i<N;i++)
            ls[s[i]-'a'].push_back(i);
        
        ls[0].push_back(N+1);
        ls[1].push_back(N+1);
        ls[2].push_back(N+1);
        
        int ind_a =0, ind_b = 0 , ind_c = 0;
        
        int ans = 0;
        
        for(int i = 0;i<N;i++){
            
            while(ind_a<ls[0].size() and ls[0][ind_a]<i)
                ind_a++;
            
            while(ind_b<ls[1].size() and ls[1][ind_b]<i)
                ind_b++;
            
            while(ind_c<ls[2].size() and ls[2][ind_c]<i)
                ind_c++;
            
            int last_ind = max({ls[0][ind_a] , ls[1][ind_b], ls[2][ind_c]});
            
            if(last_ind>=N)
                break;
            
            ans += N - last_ind;
        }
        
        return ans;
        
        
    }
};
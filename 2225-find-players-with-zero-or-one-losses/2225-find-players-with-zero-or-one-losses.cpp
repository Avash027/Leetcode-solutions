class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> lost;
        unordered_map<int,int> pres;
        
        vector<vector<int>> ans(2);
        
        for(const auto& e:matches){
            pres[e[0]] = pres[e[1]] = 1;
            lost[e[1]]++;
        }
        
        for(auto e:pres){
            if(lost[e.first] == 0) ans[0].push_back(e.first);
            else if(lost[e.first] == 1) ans[1].push_back(e.first);
        }
        
        sort(begin(ans[0]),end(ans[0]));
        sort(begin(ans[1]),end(ans[1]));
        
        return ans;
    }
};
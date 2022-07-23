// pair<int,int> = timestamp, type
// 1 - bloom start
// -1- bloom end
// 2 - isPerson

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<vector<int>> v;
        
        for(auto&e:flowers){
            v.push_back({e[0] , 1,-1});
            v.push_back({e[1]+1,-1,-1});
        }
        
        for(int i = 0;i<persons.size();i++)
            v.push_back({persons[i],2,i});
        
        
        sort(begin(v),end(v));
        
        vector<int> res(persons.size(),0);
        int cnt_flowers = 0;
        
        for(auto e:v){
            if(e[1] == 2)
                res[e[2]] = cnt_flowers;
            else
                cnt_flowers+=e[1];
        }
        
        return res;
        
    }
};
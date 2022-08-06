class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> index;
        const int N = target.size();
        
        for(int i = 0;i<N;i++)
            index[target[i]] = i;
        
        vector<int> lis;
        
        for(int&e:arr){
            if(index.find(e) == index.end())
                continue;
            
            if(lis.empty() || index[e] > lis.back())
                lis.push_back(index[e]);
            else{
             auto itr = lower_bound(begin(lis),end(lis),index[e]);
             *itr = index[e];
            }
    
        }
        
        return N - lis.size();
        
    }
};
class Solution {
private:
    bool isPal(string s , int submask){
        int ind = 0;
        string s1;
        int temp = submask;
        while(submask){
            if(submask&1) s1.push_back(s[ind]);
            ind++;
            submask>>=1;
        }
        
        
        int lo = 0;
        int hi = (int)s1.size()-1;
        
        
        while(lo<=hi) if(s1[lo++]!=s1[hi--]) return false;
        return true;
    }
public:
    int maxProduct(string s) {
        const int N = s.size();
        int mask = (1<<N)-1;
        vector<int> v;
        int ans = 0;
        
        for(int sub = mask;sub;sub = (sub-1)&mask){
            if(isPal(s,sub)) v.push_back(sub);
        }
        
    
        // for(int e:)
        for(int i = 0;i<v.size();i++)
            for(int j = 0;j<v.size();j++)
                if((v[i]&v[j])==0 and i!=j) 
                    ans = max(ans , __builtin_popcount(v[i])*
                                    __builtin_popcount(v[j])
                             );
    
        return ans;
    }
};
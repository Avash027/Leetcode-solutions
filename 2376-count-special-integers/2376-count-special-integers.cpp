class Solution {
private:
    
    //Precomputing code
    long long fact(long long n){
        return n == 1?1:n*fact(n-1);
    }
    
    long long countUnique(long long n){
        if(n == 0)
            return 0;
        
        return (9 * fact(9)/ fact(10 - n));
    }
    
    
    long long compute(string& n,int ind,vector<bool>&used,bool atMax = false){
        if(ind == n.size())
            return 1;
        
        
        long long ans = 0;
        
        if(ind == 0){
            for(char c = '1';c<=n[ind];c++){
                if(used[c-'0']) continue;
                used[c-'0'] = true;
                ans+=compute(n,ind+1,used,(c == n[ind]));
                used[c-'0'] = false;
            }
        }else{
            for(char c = '0';c<=(atMax?n[ind]:'9');c++){
                if(used[c-'0']) continue;
                used[c-'0'] = true;
                ans+=compute(n,ind+1,used,(atMax and c==n[ind]));
                used[c-'0'] = false;
            }
        }
       
        return ans;
        
    }
public:
    int countSpecialNumbers(int n) {
        vector<long long> prev(10 , 0);
        
        
        for(int i = 1;i<=9;i++){
            prev[i] = prev[i-1] + countUnique(i);
        }
        

        
        string s = to_string(n);
        
        long long ans = prev[s.size()-1];
        
        vector<bool> used(10,false);
        ans+=compute(s,0,used);
        
        
        return (int)ans;
    }
};
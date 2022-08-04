class Solution {
public:
    int distinctEchoSubstrings(string text) {
        const int MOD = 1e9+7;
        const int N = text.size();
        const int p = 31;
        
        vector<long long> p_pow(N+1 , 0);
        vector<long long> hash(N,0);
        p_pow[0] = 1; 
        
        
        for (int i = 1; i < (int)p_pow.size(); i++) 
            p_pow[i] = (p_pow[i-1]%MOD * p%MOD) % MOD;
        
        hash[0] = (text[0] - 'a'+1);
        
        for(int i = 1;i<N;i++)
            hash[i] = (hash[i-1] + (text[i]-'a'+1)*p_pow[i])%MOD;
        
        unordered_set<long long> ans;
        
        for(int i = 0;i<N;i++)
            for(int j = i+1;j<N;j++){
                int mid = (i+j)/2;
                
                long long left = (hash[mid] - (i>0?hash[i-1]:0) + MOD)%MOD;
                long long right = (hash[j] - (mid>=0?hash[mid]:0) + MOD)%MOD;
                
                if(p_pow[mid+1-i]*left%MOD == right){
                    long long total_hash = (hash[j] - (i>0?hash[i-1]:0) + MOD)%MOD;
                    (total_hash *= p_pow[N-i])%=MOD;
                    ans.insert(total_hash);
                }

            }

        
        return (int)ans.size();
    }
};
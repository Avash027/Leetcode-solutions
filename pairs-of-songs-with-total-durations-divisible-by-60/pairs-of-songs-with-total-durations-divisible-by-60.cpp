class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& arr) {
      map<int,int> freq;
        int ans = 0;
        
        for(int e:arr){
            ans+=freq[60 - e%60];
            if(e%60!=0) freq[e%60]++;
            else freq[60]++;
        }
        return ans;
    }
};
constexpr int MOD = 1e9+7;

class Solution {
private:
    long long getMaxDifference(vector<int>&arr,int l){
        sort(begin(arr),end(arr));
        int ans = 0;
        int prev = 0;
        arr.push_back(l);
        
        for(int&e:arr){
            ans = max(ans , e - prev);
            prev = e;
        }
        
        return ans%MOD;
        
    }
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        return int((getMaxDifference(hc,h)*getMaxDifference(vc,w))%MOD);
        
        
        
    }
};
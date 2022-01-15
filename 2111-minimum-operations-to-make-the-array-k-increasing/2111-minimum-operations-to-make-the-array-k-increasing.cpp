class Solution {
private:
    int LIS(vector<int>&arr){
        vector<int> lis;
        
        for(int e:arr){
            if(lis.size()==0) lis.push_back(e);
            else if(e>=lis.back()) lis.push_back(e);
            else{
                auto itr = upper_bound(lis.begin(),lis.end(),e);
                *itr = e;
            }
        }
        
        return lis.size();
    }
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;
        
        for(int i = 0;i<k;i++){
            vector<int> temp;
            
            for(int j = i;j<arr.size();j+=k)
                temp.push_back(arr[j]);
            
            ans+=temp.size() - LIS(temp);
        }
        
        return ans;
    }
};
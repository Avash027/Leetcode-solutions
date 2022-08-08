constexpr double EPS = 1e-7;

class Solution {
private:
    bool isPossible(vector<double>&arr){
        
        
        const int N = arr.size();
        
        if(N == 1) return fabs(arr[0] - 24) <EPS;
        
        for(int i = 0;i<N;i++)
            for(int j = i+1;j<N;j++){
                vector<double> temp;
                
                for(int k = 0;k<N;k++)
                    if(k!=i and k!=j)
                        temp.push_back(arr[k]);
                
                temp.push_back(arr[i] + arr[j]);
                if(isPossible(temp)) return true;
                
                temp.back() = (arr[i] - arr[j]);
                if(isPossible(temp)) return true;
                
                temp.back() = (arr[j] - arr[i]);
                if(isPossible(temp)) return true;
                
                temp.back() = (arr[i] * arr[j]);
                if(isPossible(temp)) return true;
                
                if(fabs(arr[j] - 0) > EPS){
                    temp.back() = (arr[i] / arr[j]);
                    if(isPossible(temp)) return true;
                
                }
                
                if(fabs(arr[i] - 0) > EPS){
                    temp.back() = (arr[j] / arr[i]);
                    if(isPossible(temp)) return true;
                
                }
                
            }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> arr(begin(cards),end(cards));
        return isPossible(arr);
    }
};
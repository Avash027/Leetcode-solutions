class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> arr;
        
        string s = to_string(n);
        
        
        while(s.size()){
            arr.push_back(n%10);
            n/=10;
            s.pop_back();
        }
        
        
        sort(begin(arr),end(arr));
        
        do{
            long long num = 0;
            
            if(arr[0] == 0)
                continue;
                
            
            
            for(int i = 0;i<arr.size();i++){
                (num*=10)+=arr[i];
            }
            
            
            
                if(__builtin_popcountll(num) == 1)
                    return true;
            
        }while(next_permutation(begin(arr),end(arr)));
        
        return false;
    }
};
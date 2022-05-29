class Solution {
private:
    int generateMask(const string&s)
    {
        int num = 0;
        for(const char&c:s)
            num|=(1<<(c-'a'));
        
        return num;
    }
public:
    int maxProduct(vector<string>& words) {
        const int N = words.size();
        int ans = 0;
        
        vector<int> nums(N);
        
        for(int i = 0;i<N;i++)
            nums[i] = generateMask(words[i]);
        
        
        for(int i = 0;i<N;i++)
            for(int j = i+1;j<N;j++){
                if((nums[i]&nums[j]) != 0) continue;
                
                ans = max(ans , int(words[i].size() * words[j].size()));
            }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        map<int,int> found;
        
        for(int i = 0;i<9;i++)
            for(int j = 0;j<9;j++){
                string t = s.substr(i,j-i+1);
                if(t.size()==0 or found[stoi(t)]) continue;
                int num = stoi(t);
                if(num>=low and num<=high) ans.push_back(num) , found[num]++;        
            }
        
        sort(begin(ans),end(ans));
        return ans;
    }
};
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int N = s.size();
        int wlen = words[0].size();
        int windowSize = (int)words.size() * wlen;
        
        
        if(windowSize>N)
            return {};
        
        unordered_map<string,int> freq;
        
        vector<int> ans;
        
        for(auto&e:words)
            freq[e]++;
        
        
        for(int i = 0;i<N - windowSize+1;i++){
            unordered_map<string,int> freq1 = freq;
            
            
            int j = i;
            int cnt = 0;
            
            for(int j = i;j<=i+windowSize;j+=wlen){
            string tmp = s.substr(j ,wlen);
                

            if(freq1.find(tmp)!=freq1.end() and --freq1[tmp]>=0)
                cnt++;
            else
                break;
            }
            
            if(cnt*wlen == windowSize)
                ans.push_back(i);
            
        }
        
        return ans;
        
        
    }
};

  // for(int i = 0; i < n - total * len + 1; i++){
  //           int j = i;
  //           unordered_map<string, int> stats = freq;
  //           int covered = 0;
  //           while(covered < total && j + len - 1 < n) {
  //               string word = s.substr(j, len);
  //               if(stats.find(word) != stats.end() && --stats[word] >= 0) { 
  //                   covered++;
  //                   j += len;
  //               }else break;
  //           }
  //           if(covered == total) answer.push_back(i);
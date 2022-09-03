class Solution {
private:
    
    inline int len(int& num){
        return floor(log10(num)+1);
    }

    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        vector<int> ans;
        
        for(int i = 1;i<=9;i++)
            q.push(i);
        
        while(!q.empty()){
            int num = q.front();
            q.pop();
            
            if(len(num) == n){
                ans.push_back(num);
                continue;
            }
            
            for(int i = 0;i<=9;i++)
                if(abs(i - num%10) == k)
                    q.push(num*10 + i);
        }
        return ans;
    }
};
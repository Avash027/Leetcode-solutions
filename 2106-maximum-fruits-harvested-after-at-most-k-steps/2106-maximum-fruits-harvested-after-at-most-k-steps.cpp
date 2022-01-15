class Solution {
private:
    int n;
    vector<int> pre;
    
     int query(int l,int r){
        return pre[r] - (l<=0?0:pre[l-1]);
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = 1000000;
        int ans=  0;
        pre.assign(n , 0);
        
        for(auto&e:fruits) pre[e[0]]+=e[1];
        for(int i =1;i<n;i++) pre[i]+=pre[i-1];
   
        
        
        for(int i = startPos;i<n;i++){
            
            if(i-startPos>k) break;
            int temp = query(startPos,i);
            
            
            int left = k - 2*(i-startPos);
            
            if(left>0 and startPos>0)
                temp+=query(startPos-left , startPos-1);
            
            ans = max(ans,temp);
        }
        
        for(int i = startPos;i>=0;i--){
            if(startPos-i>k) break;
            
            int temp = query(i,startPos);

            int left = k - 2*(startPos-i);
            if(left>0 and startPos+1<n)
                temp+=query(startPos+1 , startPos+left);
            
            
            ans = max(ans,temp);
        }
        
        return ans;
    }
};
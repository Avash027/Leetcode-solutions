class Solution {

private:
    
    bool areIntersecting(vector<int>&a , vector<int>&b){
        if(a[0]>b[1] || a[1] < b[0])
            return false;
        
        return true;
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        
        const int N1 = fl.size();
        const int N2 = sl.size();
        
        if(N1== 0 || N2 == 0)
            return {};
        

        
        vector<vector<int>> ans;
        
        
        for(int i = 0;i<N1;i++)
            for(int j = 0;j<N2;j++)
            if(areIntersecting(fl[i],sl[j]))
                ans.push_back(vector<int>{max(fl[i][0],sl[j][0]) , min(fl[i][1] , sl[j][1])});
        
        sort(begin(ans),end(ans));
        
        return ans;
        
    }
};
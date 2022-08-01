class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>n)swap(n,m);
        long long ans =1;
        m-- , n--;
       
        int k =1;
        for(int i =m+n;i>n and k<=m;i-- , k++){
            ans*=i;
            ans/=k;
        }
        return (int)ans;
    }
};
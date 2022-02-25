class Solution {
private:
    vector<int> stringToVector(string s){
        vector<int> v;
        s.push_back('.');
        
        string temp = "";
        
        for(int i = 0;i<s.size();i++){
            if(s[i]=='.'){
                v.push_back(stoi(temp));
                temp="";
            }else{
                temp.push_back(s[i]);
            }
        }
        
        return  v;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> a = stringToVector(version1);
        vector<int> b = stringToVector(version2);
        
        while(a.size()<b.size()) a.push_back(0);
        while(b.size()<a.size()) b.push_back(0);
        
        if(a<b) return -1;
        else if(a>b) return 1;
        else return 0;
    }
};
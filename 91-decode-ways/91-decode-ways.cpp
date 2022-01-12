class Solution {
public:
    int numDecodings(string s) {
         int a = 0, b = 1, c = 0;
        s = "0" + s;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != '0') c += b;
            if ("09" < s.substr(i - 1, 2) && s.substr(i - 1, 2) < "27") c += a;
            a = b;
            b = c;
            c = 0;
        }
        return s.empty() ? 0 : b;
    }
};
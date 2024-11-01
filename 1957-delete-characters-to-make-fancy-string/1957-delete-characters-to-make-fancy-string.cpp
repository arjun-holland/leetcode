class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3)return s;
        string r = "";
        r += s[0];
        r += s[1];
        for(int i=2;i<s.length();i++){
            if(s[i-1]==s[i-2] && s[i-1] == s[i]){
                continue;
            }
            r += s[i];
        }
        return r;
    }
};
class Solution {
public:
    bool isCircularSentence(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')continue;
            if(s[i-1]!=s[i+1])return false;
        }
        return s[0]==s[s.length()-1];
    }
};
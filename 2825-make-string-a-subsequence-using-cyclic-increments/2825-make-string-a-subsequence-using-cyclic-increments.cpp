class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int j = 0; 
        int i = 0;
        
        while(i<s1.size() && j<s2.size()){
            if((s1[i] == s2[j])||
               (s1[i]+1 == s2[j])||
               (s1[i]-25 == s2[j])){   //z=>25 : a=>0
                   j++;
               }
            i++;
        }
        
        return j == s2.length();
    }
};
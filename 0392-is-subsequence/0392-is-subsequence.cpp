class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int n = t.size();
        int m = s.size();
        
        while(i<n && j<m){
            if(t[i] == s[j]){
                j++;
            }
            i++;
        }
        return j == m;
    }
};
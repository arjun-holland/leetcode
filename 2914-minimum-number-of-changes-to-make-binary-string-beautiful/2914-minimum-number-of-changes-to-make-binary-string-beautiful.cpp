class Solution {
public:
    int minChanges(string s) {
        int re = 0;
        for(int i=0;i<s.size()-1;i+=2){//i+=2 :as two char are checked increase the iterator by 2
            if(s[i]!=s[i+1]){
                re++; 
            }
        }
        return re;
    }
};
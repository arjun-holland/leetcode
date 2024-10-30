class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string r="";
        int i=0;
        int j=0;
        bool b = true;
        while(i<word1.size() && j<word2.size()){
            if(b){
                r+=word1[j++];
                b=false;
            }
            if(!b){
                r+=word2[i++];
                b=true;
            }
        }
        while(i<word1.size()){
            r+=word1[i++];
        }
        while(j<word2.size()){
            r+=word2[j++];
        }
        return r;
    }
};
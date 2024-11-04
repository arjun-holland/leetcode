class Solution {
public:
    string compressedString(string word) {
        int s = word.length();
        string re = "";
        int i=0;
        
        while(i<s){    // total time complexity is O(n) as we run on every char at once
            int c = 0;
            char ch = word[i];
            while(i<s && c<9 && word[i]==ch){
                i++;
                c++;
            }
            re += to_string(c)+ch;
        }
        return re;
    }
};
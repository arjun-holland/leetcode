class Solution {
public:
    bool isPalindrome(string s,int i,int j){
        while(i <= j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.length()-1,k=1;
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else {// Check both possibilities: skip left or skip right
                return isPalindrome(s,i+1,j)||isPalindrome(s,i,j-1);
            }
        }
        return true;
    }
};
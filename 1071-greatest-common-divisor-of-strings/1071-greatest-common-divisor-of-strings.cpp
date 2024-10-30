class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1)
            return "";
        
        int GCD = gcd(str1.size(),str2.size());//gives the length of the string to be returned
        return str1.substr(0,GCD);
    }
};
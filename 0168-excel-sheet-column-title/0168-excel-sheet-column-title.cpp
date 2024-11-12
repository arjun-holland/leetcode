class Solution {
public:
    /*
N = 2002 corresponds to BXZ
In terms of base 26:
N=(B+1)⋅26^2+(X+1)⋅26^1+(Z+1)∗26^0  // A=1,B=2,..z=26
N=(1+1)⋅676+(23+1)⋅26+(25+1)⋅1=2002
    */
    string convertToTitle(int cn) {
        string s;  //tc : O(log26(n)) ; sc : O(1)
        while(cn){
            cn--;  //shifts the indexing to zero-based
            s = (char)(cn%26+'A') + s;
            cn = cn/26;
        }
        return s;
    }
};
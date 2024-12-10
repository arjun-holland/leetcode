class Solution {
public:
    bool isPalindrome(int x) {
      /* int r=0,t=x;
       while(x>0){
        int rr=x%10;
        if (r > INT_MAX /10 || r < INT_MIN /10) {
            return 0; // Return 0 if it overflows
        }
        r=r*10+rr;
        x/=10;
       }
       if(t==r)return true;
       return false;
       */
        if(x < 0 || (x % 10 == 0 && x!=0))return false;
        int r = 0;
        while(x > r){
            int re = x % 10;
            r = r*10 + re;
            x = x/10;
        }
        return (x == r) || (x == r/10);
    }
};
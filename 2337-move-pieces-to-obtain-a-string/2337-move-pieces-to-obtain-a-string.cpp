//here no.of possibilities are more so we use recursion technique 
//to improve recursion we use memoization technique
class Solution {
public:
    /* bool check(string st,string tt,unordered_map<string,bool>& mp,int& n){
      if(st == tt)return true;
        
        if(mp.count(st))return mp[st];
        
        for(int i=0;i<n;i++){
            if(st[i]=='L' && i>0 && st[i-1]=='_'){
                swap(st[i],st[i-1]);
                if(check(st,tt,mp,n)==true)
                    return true;
                swap(st[i],st[i-1]);
            }
            else if(st[i]=='R' && i<n-1 && st[i+1]=='_'){
                swap(st[i],st[i+1]);
                if(check(st,tt,mp,n)==true)
                    return true;
                swap(st[i],st[i+1]);
            }
        }
        return mp[st]=false;
    }
    bool canChange(string st, string tt) {
        unordered_map<string,bool> mp;  //gives memory limited exceeded
        int n = st.size();
        return check(st,tt,mp,n);*/
    bool canChange(string st, string tt) {
        int n=st.length();
        int i=0,j=0;         //i : st and j : tt
      while(i<n || j<n){
          while(i<n && st[i] == '_')i++;
          while(j<n && tt[j] == '_')j++;
          if(i==n || j==n){
            return i==n&&j==n;
          }
          if(st[i] != tt[j])return false;
          if(st[i] == 'L' && i<j)return false;//cant move to the right
          if(st[i] == 'R' && i>j)return false;//cant move to the left 
          i++;
          j++;
       }    
     return true;
    }
};
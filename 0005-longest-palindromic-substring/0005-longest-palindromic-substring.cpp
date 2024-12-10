class Solution {
public:
    
    string isPalindrome(string& s,int l,int r){ //Expand-Around-Center Method
        
        while(l>=0 && r<= s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        
        return s.substr(l+1,r-l-1);
        
    }
    string longestPalindrome(string s) { //O(n^2)
        if(s.length()<=1)return s;
        
        int max_ans = 1;
        string ans = s.substr(0,1);
        
        for(int i=0; i < s.length(); i++){
            
            string oddSub = isPalindrome(s, i, i);
            string evenSub = isPalindrome(s, i, i+1);
            
            if(max_ans < oddSub.length()){
                ans = oddSub;
                max_ans = oddSub.length();
            }
            if(max_ans < evenSub.length()){
                ans = evenSub;
                max_ans = evenSub.length();
            }
            
        }
        return ans;
    }
};
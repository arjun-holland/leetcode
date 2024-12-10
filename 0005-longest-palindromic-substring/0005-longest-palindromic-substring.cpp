class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(string& s,int l,int r){ //dp
        if(l>=r)return true;
        
        if(dp[l][r] != -1)return dp[l][r];
        
        if(s[l] == s[r])
             return dp[l][r] = isPalindrome(s , l+1 , r-1);
                    
        return dp[l][r] = false;
    }
    string longestPalindrome(string s) { //O(n^2)
        if(s.length()<=1)return s;
        
        int max_ans = 1;
        int st_Ind = 0;
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0; i < s.length(); i++){
            for(int j=i; j < s.length(); j++){
                if(isPalindrome(s,i,j)){
                    if(max_ans < (j-i+1)){
                        max_ans = j-i+1;
                        st_Ind = i;
                    }
                }
            }
        }
        return s.substr(st_Ind, max_ans);
    }
};
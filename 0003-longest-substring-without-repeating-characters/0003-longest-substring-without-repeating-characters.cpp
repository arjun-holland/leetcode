class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        
        for(int j=0,i=0;i<s.length();i++){
            if(!mp.empty() && mp[s[i]] > 0){
               j = max(j,mp[s[i]]); 
            }
            mp[s[i]] = i+1;
            ans = max(ans,i-j+1);    
        }
        return ans; 
    }
};
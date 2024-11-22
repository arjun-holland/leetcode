class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>,int> mp;   //TC : O(n*m)
        int ans = 0;
        
        for(auto& row : matrix){//O(n)
            vector<int> v;
            
            if(row[0])v = row;     //if row has 1 it is v
            else for(auto& i : row)v.push_back(i^1);  //flip that row  //O(m) 
            
            ans = max(ans,++mp[v]);  //push v into map and increment  
        }
        return ans;
    }
};
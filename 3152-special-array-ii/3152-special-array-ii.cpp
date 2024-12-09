class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       /* 
       vector<bool> ans(queries.size(),false); //O(n^2)
        for(int i=0;i<queries.size();i++){
            int si = queries[i][0];
            int ei = queries[i][1];
            
            for(int i=si+1;i<=ei;i++){
                if(nums[i]%2 == nums[i-1]%2){
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans;
        */
        
        /*
        vector<int> v(nums.size());
        v[0]=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2 == nums[i-1]%2){
                v[i] = v[i-1]+1;
            }else{
                v[i] = v[i-1];
            }
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int si = queries[i][0];
            int ei = queries[i][1];
            if(v[ei] - v[si] == 0)
                ans.push_back(true);
            else 
                ans.push_back(false);
        }
        return ans;
        
        */
        int n=nums.size();
        vector<int> v(n); //parity end index array
        int i=0,j=0;
        while(i<n){
            if(j < i){
                j = i;
            }
            while(j+1<n && nums[j]%2 != nums[j+1]%2){
                j++;
            }
            v[i] = j;
            i++;            
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int si = queries[i][0];
            int ei = queries[i][1];
            if(v[ei] <= v[si])
                ans.push_back(true);
            else 
                ans.push_back(false);
        }
        return ans;
        
        
    }
};
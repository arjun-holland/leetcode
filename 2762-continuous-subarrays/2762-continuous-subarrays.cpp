class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        int i=0,j=0;
        long long count = 0;
        //i is used to compress the window and 
        //j is used to expand the window
        
        while(j<n){
            mp[nums[j]]++;
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2){
                mp[nums[i]]--; 
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;  //decrease the window size
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
};
//we use map as All the elements of the subarray are distinct we can use set also but it wont make frequency of that elements
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; 
        long long res = 0 , cursum = 0;
        
        for(int i=0;i<nums.size();i++){
            cursum += nums[i];
            mp[nums[i]]++; //push element and increase frequency
            
            if(i >= k-1){
                if(mp.size() == k) 
                    res = max(res,cursum);
                cursum -= nums[i-k+1];  //update the sum by removing thr first ele
                mp[nums[i-k+1]]--;  //reduce the first ele freq
                if(mp[nums[i-k+1]] == 0)  //as size of map matters remove unwanted ele
                    mp.erase(nums[i-k+1]);
            }
        }
        return res;
    }
};
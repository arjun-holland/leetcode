/*As things are not linearly increasing or decreasing (-105 <= nums[i] <= 105) in this sum we have to use sliding windows technique rather then two  pointers*/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> mph;//minheap
        int res = INT_MAX;
        long long cs = 0;//current sum
        for(int i=0;i<nums.size();i++){
            cs += nums[i];
            if(cs >= k)res = min(res,i+1);
            // Remove subarrays from heap that can form a valid subarray
            while(!mph.empty() && cs-mph.top().first >= k){
                res = min(res,i-mph.top().second);
                mph.pop();
            }
            mph.push({cs,i});//mph.emplace(cs,i);
        }
        return res==INT_MAX?-1:res;
    }
};
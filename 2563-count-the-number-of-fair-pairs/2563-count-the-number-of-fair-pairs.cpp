class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        deque<int> dq;
        for(int i:nums){
            dq.push_back(i);
        }
        long long re = 0;
        for(int i=0;i<nums.size();i++){
            dq.pop_front();
            auto lo = lower_bound(dq.begin(),dq.end(),lower - nums[i]);
            auto up = upper_bound(dq.begin(),dq.end(),upper - nums[i]);
            
            re += up-lo;
        }
        return re;
    }
};
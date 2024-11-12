class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()<3)return -1;
        sort(nums.begin(),nums.end());
        int re = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        
        int re2;
        if(nums[0]<0 && nums[1]<0)re2 = nums[0]*nums[1]*nums[nums.size()-1];
        return re > re2 ? re : re2;
        
    }
};
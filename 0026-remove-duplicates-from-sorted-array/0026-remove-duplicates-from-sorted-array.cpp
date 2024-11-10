class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int r = 0,j=0;
        nums[j]=nums[0];
        j++;
        r++;//length of unique elements
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])continue;
            nums[j]=nums[i];
            j++;
            r++;
        }
        return r;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int sp=1 ,ep=1;
        for(int i=0;i<n;i++){
            sp *= nums[i];
            ep *= nums[n-1-i];
            ans = max({ans,sp,ep});
            if(nums[i] == 0){
                sp = 1;
            }
            if(nums[n-i-1] == 0){
                ep = 1;
            }
        }
        return ans;
    }
};
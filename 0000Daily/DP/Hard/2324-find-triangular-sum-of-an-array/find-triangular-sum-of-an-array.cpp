class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        
        while (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;  // Modulo 10 as per triangular sum rules
            }
            n--;  // Reduce the size for the next iteration
        }

        return nums[0];
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());  // Sort the array

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;// Skip duplicate elements

            int left = i + 1; // Left pointer
            int right = nums.size() - 1; // Right pointer

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate elements for left pointer
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicate elements for right pointer
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++; // We need a larger sum
                } else {
                    right--; // We need a smaller sum
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*while(k--){            // total time complexity : O(k⋅n)
            int e = nums[nums.size()-1];   // time complexity : O(1)
            nums.pop_back();     // time complexity : O(1)
            nums.insert(nums.begin(),e);  // time complexity : O(n)
        }*/
        int n = nums.size();  //total time complexity is O(n)+O(k)+O(n−k) = O(n)
        k = k % n;          //to handle when  k > nums.size() value
        reverse(nums.begin(),nums.end());   // time complexity : O(n)
        reverse(nums.begin(),nums.begin()+k); // time complexity : O(k)
        reverse(nums.begin()+k,nums.end());   // time complexity : O(n-k)

    }
};
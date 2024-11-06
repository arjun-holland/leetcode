class Solution {
public:
    bool canSortArray(std::vector<int>& nums) {
//using bubble sorting algorithm bnut here swap only when the adjucent elements have same set bits
//tc : O(n^2)
//sc : O(1)
        bool s = true;
        for(int i=0;i<nums.size();i++){
            s = false;
            for(int j=0;j<nums.size()-i-1;j++){//per iteration largest element reach right most position
                if(nums[j]<=nums[j+1])continue;
                else {
                     if(__builtin_popcount(nums[j])==__builtin_popcount(nums[j+1])){
                      swap(nums[j],nums[j+1]);
                      s = true;
                     }
                     else return false;
                }    
            }
            if(s == false)break;//means elements are sorted
            }
         return true;   
        }
};
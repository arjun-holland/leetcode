class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*sort(nums.begin(),nums.end());   //O(n logn)
        return nums[(0+nums.size())/2];*/

        int e;              // using moore's voting algorithm
        int c = 0;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                e = nums[i];
                c=1;
            }
            else if(e==nums[i])c++;
            else c--;
        }
        return e;
    }
};
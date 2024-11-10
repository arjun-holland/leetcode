class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> dn;
        for(int &i:nums){
            if(i != 0)
                dn.push_back(i);
        }
        int s = nums.size()-dn.size();
        while(s>0){
            dn.push_back(0);
            s--;
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = dn[i];
        }
    }
};
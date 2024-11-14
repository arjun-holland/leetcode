class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> a;
        vector<int> e;
        for(int i=0;i<nums.size();i++){
            if(a.find(nums[i])!=a.end()){
                e.push_back(nums[i]);
            }else
            a.insert(nums[i]);
        }
        return e;
    }
};
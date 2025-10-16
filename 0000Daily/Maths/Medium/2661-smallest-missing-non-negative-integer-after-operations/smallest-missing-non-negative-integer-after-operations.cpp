class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int mod = ((nums[i] % value) + value) % value;
            mp[mod]++;
        }

        int ans = 0;
        while(true){
            int mod = ans % value;
            if(mp[mod] > 0){
                mp[mod]--;
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};
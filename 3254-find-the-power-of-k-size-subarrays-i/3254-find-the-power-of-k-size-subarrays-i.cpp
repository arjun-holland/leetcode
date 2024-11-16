class Solution {
public:
    int check(vector<int>& a,int k){
        for(int i=0;i<k-1;i++){
            if(a[i]+1 != a[i+1])return -1;
        }
        return *max_element(a.begin(),a.end());
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k){
            int s = n-k+1;
            vector<int> res(s,-1);
            return res;
        }
        vector<int> ans;
        for(int i=0; i<=n-k; i++){
            vector<int> a;
            for(int j=i; j<i+k; j++){
                a.push_back(nums[j]);
            }
            int e = check(a,k);
            ans.push_back(e);
        }
        return ans;
    }
};
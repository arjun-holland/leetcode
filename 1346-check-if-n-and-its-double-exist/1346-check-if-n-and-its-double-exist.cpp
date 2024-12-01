class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        for(int i=0;i<arr.size();i++){
            int re = arr[i]/2;
            if(arr[i] % 2 == 0)
              if(mp.find(re) != mp.end()){
                if(mp[re] != i)
                    return true;
              }
        }
        return false;
    }
};
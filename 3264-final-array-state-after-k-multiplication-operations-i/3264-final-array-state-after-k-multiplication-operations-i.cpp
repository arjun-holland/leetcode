/*
 int n = nums.size();
        
        vector<pair<int,int>> vec(n);//O(n)
        for(int i=0;i<n;i++){
            vec[i] = {nums[i],i};
        }
        make_heap(vec.begin(),vec.end(),greater<>());//making min heap with vector
        
        while(k--){//O(k*logn)
            pop_heap(vec.begin(),vec.end(),greater<>());//first ele reaches last pos in min heap
            pair<int,int> temp = vec.back();
            vec.pop_back();   //removes the last element
            int e = temp.first;
            int ind = temp.second;
            int ne = e*multiplier;  //modification
            nums[ind] = ne;   
            vec.push_back({nums[ind],ind});  
            push_heap(vec.begin(),vec.end(),greater<>()); //new elem is added to heap 
        }
        return nums;
*/
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> mh;
       for(int i=0;i<nums.size();i++){//O(nlogn)
           mh.push({nums[i],i});
       }
       while(k--){//O(k logn)
           auto p = mh.top();
           mh.pop();
           int e = p.first;
           int in = p.second;
           nums[in] = e*multiplier;
           mh.push({nums[in],in});
       } 
       return nums; 
        
    }
};
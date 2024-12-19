class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> a;
        for(int e:arr){
            a.push_back(e);
        }
        sort(a.begin(),a.end());
        int chunks = 0;
        int qs = 0,as = 0;
        for(int i=0;i<arr.size();i++){
            qs += arr[i];
            as += a[i];
            if(qs == as){
                chunks++;
                qs=0;
                as=0;
            }
        }
        return chunks;
    }
};
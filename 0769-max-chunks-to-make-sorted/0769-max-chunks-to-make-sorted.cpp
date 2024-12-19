class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       
        int chunks = 0;
        int qs = 0,as = 0;
        for(int i=0;i<arr.size();i++){
            qs += arr[i];
            as += i;
            if(qs == as){
                chunks++;
                qs=0;
                as=0;
            }
        }
        return chunks;
    }
};
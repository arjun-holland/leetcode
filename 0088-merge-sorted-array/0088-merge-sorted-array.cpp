class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        vector<int> r=n1;  
        for(int i:n2){
            r[m++]=i;
        }
        sort(r.begin(),r.end()); //O(n logn)
        int j=0;
        for(int i:r){
            n1[j++]=i;
        }
    }
};
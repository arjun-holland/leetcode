class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> mh;
        for(int i=0;i<gifts.size();i++){
            mh.push(gifts[i]);
        }
        while(k--){
            int e = mh.top();
            mh.pop();
            int ne = floor(sqrt(e));
            mh.push(ne);
        }
        int i=0;
        while(!mh.empty()){
            gifts[i] = mh.top();
            mh.pop();
            i++;
        }
        long long ans = 0;
        for(int i=0;i<gifts.size();i++){
            ans += gifts[i];
        }
        return ans;
    }
};
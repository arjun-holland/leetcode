# PROBLEM
<img width="1635" height="897" alt="image" src="https://github.com/user-attachments/assets/8db7fe16-ee1b-488f-ab48-e6dcaf6ddf76" />

```
Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
There are a total of 7 unguarded cells, so we return 7.
```


# CODE
```
class Solution {
public:
    void make(vector<vector<char>>& gd,int i,int j){

        int ni = i, nj = j+1;  //left
        while(nj < gd[0].size()){
            if(gd[ni][nj] == 'v'){
                nj++;
                continue;
            }
            if(gd[ni][nj] == 'g' || gd[ni][nj] == 'w')break;
            gd[ni][nj] = 'v';
            nj++;
        }

        ni = i, nj = j-1;  //right
        while(nj >= 0){
            if(gd[ni][nj] == 'v'){
                nj--;
                continue;
            }
            if(gd[ni][nj] == 'g' || gd[ni][nj] == 'w')break;
            gd[ni][nj] = 'v';
            nj--;
        }

        ni = i+1, nj = j;  //bottom
        while(ni < gd.size()){
            if(gd[ni][nj] == 'v'){
                ni++;
                continue;
            }
            if(gd[ni][nj] == 'g' || gd[ni][nj] == 'w')break;
            gd[ni][nj] = 'v';
            ni++;
        }

        ni = i-1, nj = j;  //top
        while(ni >= 0){
            if(gd[ni][nj] == 'v'){
                ni--;
                continue;
            }
            if(gd[ni][nj] == 'g' || gd[ni][nj] == 'w')break;
            gd[ni][nj] = 'v';
            ni--;
        }

    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> gd(m,vector<char>(n,'*'));
        for(auto g : guards){  //filling guards in gd matrix
            int i = g[0];
            int j = g[1];
            gd[i][j] = 'g';
        }
        for(auto w : walls){  //filling walls in gd matrix
            int i = w[0];
            int j = w[1];
            gd[i][j] = 'w';
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(gd[i][j] == 'g'){
                    make(gd,i,j);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){   //finding no.of unvisited cells ni matrix
            for(int j=0; j<n; j++){
                if(gd[i][j] == '*'){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
```

class Solution {
public:
    int m,n;
    vector<int> directions = {-1,0,1};
    int DFS(int r,int c,vector<vector<int>>& g,vector<vector<int>> &t){
        
        if(t[r][c]!=-1)return t[r][c];
        
        int moves = 0;
        
        for(int &dir:directions){
            int nr = r+dir;
            int nc = c+1;
            if(nr>=0 && nr<m && nc>=0 && nc<n && g[nr][nc]>g[r][c])//element found
                moves = max(moves,1+DFS(nr,nc,g,t));//increment move ans check further
        }
        
        return t[r][c] = moves;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int res = 0;
        m=grid.size();//rows
        n=grid[0].size();//columns
        
        vector<vector<int>> t(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){//checking every row first element
          res = max(res,DFS(i,0,grid,t));
        }
        return res;
    }
};
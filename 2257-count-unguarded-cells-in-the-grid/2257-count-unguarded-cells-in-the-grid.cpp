#include <vector>
using namespace std;

class Solution {
public:
    void setRowCol(int r, int c, vector<vector<char>>& grid, int m, int n) {
        // Check upwards
        for (int i = r - 1; i >= 0; i--) {
            if (grid[i][c] == 'W' || grid[i][c] == 'G') break;
            grid[i][c] = 'v'; // Mark as guarded
        }
        // Check downwards
        for (int i = r + 1; i < m; i++) {
            if (grid[i][c] == 'W' || grid[i][c] == 'G') break;
            grid[i][c] = 'v'; // Mark as guarded
        }
        // Check left
        for (int j = c - 1; j >= 0; j--) {
            if (grid[r][j] == 'W' || grid[r][j] == 'G') break;
            grid[r][j] = 'v'; // Mark as guarded
        }
        // Check right
        for (int j = c + 1; j < n; j++) {
            if (grid[r][j] == 'W' || grid[r][j] == 'G') break;
            grid[r][j] = 'v'; // Mark as guarded
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '.'));
        
        // Place guards in the grid
        for (auto& g : guards) {
            grid[g[0]][g[1]] = 'G';
        }
        
        // Place walls in the grid
        for (auto& w : walls) {
            grid[w[0]][w[1]] = 'W';
        }
        
        // Mark cells as visited that are guarded by each guard or well
        for (auto& g : guards) {
            setRowCol(g[0], g[1], grid, m, n);
        }
        
        // Count unguarded cells
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.') {
                    unguardedCount++;
                }
            }
        }
        
        return unguardedCount;
    }
};
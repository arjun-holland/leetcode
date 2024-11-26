class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // Vector to track incoming edges for each node
        vector<int> hasIncomingEdge(n, 0);
        
        // Mark nodes with incoming edges
        for (auto& edge : edges) {
            hasIncomingEdge[edge[1]] = 1; // Node edge[1] has an incoming edge
        }
        
        int champion = -1; // Initialize champion index
        bool foundChampion = false; 
        
        // Check for nodes with no incoming edges
        for (int i = 0; i < n; i++) {
            if (hasIncomingEdge[i] == 0) { // No incoming edges
                if (!foundChampion) {
                    champion = i; // Found a potential champion
                    foundChampion = true;
                } else {
                    // More than one candidate found
                    return -1;
                }
            }
        }
        
        return champion; // Return the index of the champion or -1 if none exists
    }
};
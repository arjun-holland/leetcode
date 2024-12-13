class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> elements; // {value, index}

        // Store elements with their indices
        for (int i = 0; i < n; i++) {
            elements.push_back({nums[i], i});
        }

        // Sort by value
        sort(elements.begin(), elements.end());

        vector<bool> visited(n, false); // Track visited indices
        long long score = 0;

        // Process elements in sorted order
        for (auto& [val, idx] : elements) {
            if (!visited[idx]) { // If not visited
                score += val; // Add the value to the score
                visited[idx] = true; // Mark the current index as visited
                if (idx - 1 >= 0) visited[idx - 1] = true; // Mark left neighbor
                if (idx + 1 < n) visited[idx + 1] = true;  // Mark right neighbor
            }
        }

        return score;
    }
};

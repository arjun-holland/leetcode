class Solution {
public:
    // Function to check if it's possible to eat all bananas at speed 'm' within 'h' hours
    bool possible(int m, vector<int>& p, int h) {
        // Iterate through each pile of bananas
        for (int &ep : p) {
            // Calculate the number of hours needed to eat the current pile at speed 'm'
            h -= (ep + m - 1) / m; // This is equivalent to ceil(ep / m)
            // If hours left are less than 0, it's not possible with this speed
            if (h < 0) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // Set initial bounds for binary search: speed cannot be less than 1 and cannot exceed the largest pile
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int re = 0; // Variable to store the result (minimum speed)

        // Perform binary search to find the minimum eating speed
        while (l <= r) {
            int m = l + (r - l) / 2; // Calculate mid-point speed

            // Check if it's possible to eat all bananas at speed 'm' within 'h' hours
            if (possible(m, piles, h)) {
                re = m; // If possible, store this speed as a potential result
                r = m - 1; // Try for a smaller speed
            } else {
                l = m + 1; // If not possible, increase the speed
            }
        }
        return re; // Return the minimum eating speed found
    }
};
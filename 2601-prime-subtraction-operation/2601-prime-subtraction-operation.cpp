#include <vector>
using namespace std;

class Solution {
public:
    void sieve(vector<bool> &v) {  // Function to perform the Sieve of Eratosthenes
        v[0] = false;              // 0 is not prime
        v[1] = false;              // 1 is not prime
        for (int i = 2; i * i <= 1000; i++) {
            if (v[i]) {
                for (int j = i * i; j <= 1000; j += i) { // Mark multiples of i as non-prime
                    v[j] = false;
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<bool> v(1001, true); // Boolean array to mark primes
        sieve(v); // Fill the boolean array with primes
        
        vector<int> primes;                // Vector to store prime numbers
        for (int i = 2; i <= 1000; i++) {
            if (v[i]) primes.push_back(i); // Collect all primes up to 1000
        }

        vector<int> res(nums.size(), -1);  // Resultant array initialized to -1
        res[nums.size() - 1] = nums[nums.size() - 1]; // Last element remains unchanged

        // Iterate from second last element to the first
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < res[i + 1]) {   // If current number is less than next, keep it
                res[i] = nums[i];
                continue;
            }
            for (int p : primes) { // Try subtracting each prime from nums[i]
                if (p >= nums[i]) { // If prime is greater than or equal to current number, keep it as is
                    res[i] = nums[i];
                    break;
                }
                if (nums[i] - p < res[i + 1]) { // Check if subtracting prime keeps it less than next element
                    res[i] = nums[i] - p;
                    break;
                }
            }
        }

        // Final check for strictly increasing order
        for (int i = 0; i < res.size() - 1; i++) {
            if (res[i] >= res[i + 1]) return false; // If any element is not less than the next, return false
        }

        return true; // If all checks pass, return true
    }
};
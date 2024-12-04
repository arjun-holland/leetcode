class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int j = 0; // Pointer for s2
        
        for (char c : s1) {
            // Check if we have matched all characters of s2
            if (j < s2.length()) {
                char nextChar = (c == 'z') ? 'a' : c + 1; // Increment character
                
                // Check if current character matches or can be transformed to match s2[j]
                if (c == s2[j] || nextChar == s2[j]) {
                    j++; // Move to the next character in s2
                }
            }
        }
        
        // If we've matched all characters in s2, j should equal s2.length()
        return j == s2.length();
    }
};
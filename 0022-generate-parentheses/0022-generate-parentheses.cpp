class Solution {
public:
    vector<string> ans;

    bool isValid(string s) {
        int c = 0;
        for (char ch : s) {
            if (ch == '(') c++;
            else c--;
            if (c < 0) return false; // More closing than opening
        }
        return c == 0; // Must be balanced
    }

    void solve(string& s, int n) {
        // Base case: when the string length is 2*n
        if (s.length() == 2 * n) {
            if (isValid(s)) ans.push_back(s);
            return;
        }

        s.push_back('(');
        solve(s, n);
        s.pop_back(); // Backtrack
        
        s.push_back(')');
        solve(s, n);
        s.pop_back(); // Backtrack
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        solve(s, n); // Start with an empty string
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if (s.empty())return ""; 

        sort(s.begin(), s.end());

        string first = s[0];
        string last = s[s.size() - 1];
        int j = 0;
        while (j < first.size() && j < last.size() && first[j] == last[j]) {
            j++;
        }
        return first.substr(0, j);
    }
};
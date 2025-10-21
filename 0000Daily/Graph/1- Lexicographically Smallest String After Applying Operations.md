# PROBLEM
<img width="1108" height="654" alt="image" src="https://github.com/user-attachments/assets/666637a8-a216-4104-a627-b2bb99669fc5" />
<img width="1075" height="778" alt="image" src="https://github.com/user-attachments/assets/fa50c073-db61-4f26-8710-cc12f24fbacc" />
<img width="1079" height="566" alt="image" src="https://github.com/user-attachments/assets/f82e0586-6c67-4593-86d7-f30c006d2bdb" />

# INTUITION

## HOW TO FIND DOES PARTICULAR PROBLEM NEEDS " THE DFS/BFS TECHNIQUE " :
<img width="1533" height="931" alt="image" src="https://github.com/user-attachments/assets/71f59b4d-1ce9-43b6-8521-c2fca8527cba" />

```
In the given problem ,
    we are having the number,
    we have to perform the operation in samw way for any digit in the number,
    Definately we can reach the final target i.e the string which here is lexicograpically smallest

so wqe can use the DFS or BFS here
```


# CODE : Using BFS
```
class Solution {
public:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    string findLexSmallestString(string s, int a, int b) {
        string smallestString = s;

        unordered_set<string> visited;
        queue<string> que;
        que.push(s);
        visited.insert(s);

        while(!que.empty()) {
            string curr = que.front();
            que.pop();

            if(curr < smallestString) {
                smallestString = curr;
            }

            //Add a to the digits
            string temp = curr;
            for(int i = 1; i < temp.length(); i+=2) {
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }

            if(!visited.count(temp)) {
                visited.insert(temp);
                que.push(temp);
            }

            //Rotate right by b
            rotate(curr, b);
            if(!visited.count(curr)) {
                visited.insert(curr);
                que.push(curr);
            }
        }

        return smallestString;

    }
};

```

# CODE : Using DFS
```
class Solution {
public:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    void dfs(string curr, int a, int b, unordered_set<string> &visited, string &smallestString) {
        if (visited.count(curr)) return;
        visited.insert(curr);
        if (curr < smallestString) smallestString = curr;

        string added = curr;
        for (int i = 1; i < added.size(); i += 2)
            added[i] = ((added[i] - '0' + a) % 10) + '0';
        dfs(added, a, b, visited, smallestString);

        rotate(curr, b);
        dfs(curr, a, b, visited, smallestString);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string smallestString = s;
        dfs(s, a, b, visited, smallestString);
        return smallestString;
    }
};
```

---

# BFS IN DETAIL :
```
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addToOdds(const string &s, int a) {
        string t = s;
        for (int i = 1; i < (int)t.size(); i += 2) {
            int digit = (t[i] - '0');
            digit = (digit + a) % 10;
            t[i] = char(digit + '0');
        }
        return t;
    }

    string rotateRight(const string &s, int k) {
        int n = (int)s.size();
        if (n == 0) return s;
        k %= n;
        if (k == 0) return s;
        string t = s;
        reverse(t.begin(), t.end());
        reverse(t.begin(), t.begin() + k);
        reverse(t.begin() + k, t.end());
        return t;
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);

        string ans = s;
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            if (cur < ans) ans = cur;

            // Operation 1: add 'a' to all odd indices
            string added = addToOdds(cur, a);
            if (!vis.count(added)) {
                vis.insert(added);
                q.push(added);
            }

            // Operation 2: rotate right by b
            string rotated = rotateRight(cur, b);
            if (!vis.count(rotated)) {
                vis.insert(rotated);
                q.push(rotated);
            }
        }
        return ans;
    }
};
```

# RUN HERE
https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/submissions/1807606741/?envType=daily-question&envId=2025-10-19

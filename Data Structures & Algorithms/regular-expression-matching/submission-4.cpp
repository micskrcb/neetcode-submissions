class Solution {
public:
    vector<vector<int>> dp;

    int solve(string& s, string& p, int i, int j) {
        // Base Case 1: Both strings exhausted -> Success
        if (i == s.size() && j == p.size()) return 1;
        
        // Base Case 2: Pattern exhausted but string remains -> Failure
        if (j == p.size()) return 0;

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        // Check if current characters match
        bool match = (i < s.size()) && (s[i] == p[j] || p[j] == '.');

        // Lookahead: If the next character in pattern is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Case 1: Ignore the '*' pair (0 occurrences) -> solve(i, j+2)
            // Case 2: Use the '*' pair (1+ occurrences) -> if matched, solve(i+1, j)
            bool ans = solve(s, p, i, j + 2) || (match && solve(s, p, i + 1, j));
            return dp[i][j] = ans;
        }

        // Standard matching (No '*' lookahead)
        if (match) {
            return dp[i][j] = solve(s, p, i + 1, j + 1);
        }

        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        // Size dynamically (+1 to handle the base cases where i == s.size() or j == p.size())
        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0);        
    }
};
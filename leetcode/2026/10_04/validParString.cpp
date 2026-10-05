class Solution {
public:
    bool checkValidString(string s) {
        memo.assign(s.size() + 1, vector<int>(s.size() + 1, -1));
        return solve(s, 0, 0);
    }

private:
    vector<vector<int>> memo;   // -1 = unknown, 0 = false, 1 = true

    bool solve(const string& s, int i, int open) {
        if (open < 0) return false;
        if (i == s.size()) return open == 0;             // base case: true if all open are closed

        if (memo[i][open] != -1) return memo[i][open];   // already solved

        bool ok;
        if (s[i] == '(')      ok = solve(s, i + 1, open + 1);
        else if (s[i] == ')') ok = solve(s, i + 1, open - 1);
        else                  ok = solve(s, i + 1, open + 1)
                                || solve(s, i + 1, open - 1)
                                || solve(s, i + 1, open);

        memo[i][open] = ok;
        return ok;
    }
};
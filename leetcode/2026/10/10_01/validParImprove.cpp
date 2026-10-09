class Solution {
public:
    bool isValid(string s) {
        // Odd length can never match up
        if (s.size() % 2 != 0) return false;

        // Most recent unmatched opener is always on top
        stack<char> open;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                open.push(c);
            }
            else {
                // Closer with nothing open
                if (open.empty()) return false;

                // Closer must match the most recent opener
                char top = open.top();
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;

                open.pop();
            }
        }

        // Valid only if nothing is left open
        return open.empty();
    }
};
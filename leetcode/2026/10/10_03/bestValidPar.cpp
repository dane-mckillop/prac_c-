class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int best = 0;
        scan(s, 0, st, best);
        return best;
    }

private:
    void scan(const string& s, int i, stack<int>& st, int& best) {
        // Base: end of string
        if (i == s.size()) return;

        // If '(': push index to stack
        if (s[i] == '(') {
            st.push(i);
        } 
        // If ')'
        else {
            // Remove the last unmatched '(' index
            st.pop();
            // If stack empty: push current index as new base
            if (st.empty()) {
                st.push(i); 
            } 
            // If stack not empty: calculate length of valid substring
            else {
                best = max(best, i - st.top());
            }
        }
        // Recurse to next char
        scan(s, i + 1, st, best);
    }
};
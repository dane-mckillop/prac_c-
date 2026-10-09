class Solution {
public:
    int minAddToMakeValid(const string& s) {
        return scan(s, 0, 0, 0);
    }

private:
    int scan(const string& s, int i, int open, int moves) {
        if (i >= s.size()) return moves + open; 

        if (s[i] == '(') {
            return scan(s, i + 1, open + 1, moves);
        }
        if (open > 0) {
            return scan(s, i + 1, open - 1, moves); 
        }
        return scan(s, i + 1, open, moves + 1); 
    }
};
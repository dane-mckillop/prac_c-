class Solution {
public:
    int minInsertions(const string& s) {
        return scan(s, 0, 0, 0);
    }

private:
    int scan(const string& s, int i, int open, int ins) {
        if (i >= s.size()) return ins + 2 * open;

        if (s[i] == '(') return scan(s, i + 1, open + 1, ins);

        int step = 1;
        if (i + 1 < s.size() && s[i + 1] == ')') step = 2;
        else ++ins;

        if (open > 0) --open;
        else ++ins;

        return scan(s, i + step, open, ins);
    }
};
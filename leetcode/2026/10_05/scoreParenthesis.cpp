class Solution {
public:
    int scoreOfParentheses(string s) {
        //Initialize
        int i = 0;
        int openPar = 0;
        int score = 0;

        //Iterate
        scanParenthesis(s, i, openPar, score);
        return score;
    }

private:
    void scanParenthesis(string& s, int& i, int& openPar, int& score) {
        // Base
        if (i >= s.size()) {
            return;
        }

        // Traverse
        if (s[i] == '(') {
            openPar += 1;
        }
        else {
            if (openPar > 0) {
                openPar -= 1;
                if (i > 0 && s[i-1] != ')') {
                    score += lazyExponent(2, openPar);
                }
            }
            else {
                score = -1;
                return;
            }
        }
        // Recurse
        i++;
        scanParenthesis(s, i, openPar, score);
    }

    int lazyExponent(int base, int power) {
        if (power <= 0) {
            return 1;
        }
        else {
            return base * lazyExponent(base, power-1);
        }
    }
};
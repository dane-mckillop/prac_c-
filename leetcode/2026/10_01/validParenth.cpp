class Solution {
public:
//Review: Can be optimized with a single char stack, instead of 3.
    bool isValid(string s) {
        //Initialize
        stack<int> openPar;
        int lastOpenPar = -1;
        stack<int> openCur;
        int lastOpenCur = -1;
        stack<int> openSqr;
        int lastOpenSqr = -1;

        //Iterate
        for(int i=0; i < s.size(); ++i) {
            if (s[i] == '(') {
                openPar.push(i);
                lastOpenPar = i;
            }
            else if (s[i] == ')') {
                if (openPar.empty()) return false;
                if (lastOpenCur > lastOpenPar || lastOpenSqr > lastOpenPar) {
                    return false;
                }
                else {
                    openPar.pop();
                    lastOpenPar = openPar.empty() ? -1 : openPar.top();
                }
            }
            if (s[i] == '{') {
                openCur.push(i);
                lastOpenCur = i;
            }
            else if (s[i] == '}') {
                if (openCur.empty()) return false;
                if (lastOpenPar > lastOpenCur || lastOpenSqr > lastOpenCur) {
                    return false;
                }
                else {
                    openCur.pop();
                    lastOpenCur = openCur.empty() ? -1 : openCur.top();
                }
            }
            if (s[i] == '[') {
                openSqr.push(i);
                lastOpenSqr = i;
            }
            else if (s[i] == ']') {
                if (openSqr.empty()) return false;
                if (lastOpenPar > lastOpenSqr || lastOpenCur > lastOpenSqr) {
                    return false;
                }
                else {
                    openSqr.pop();
                    lastOpenSqr = openSqr.empty() ? -1 : openSqr.top();
                }
            }
        }
        //Finalize
        if (openPar.empty() && openCur.empty() && openSqr.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
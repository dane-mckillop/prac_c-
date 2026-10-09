class Solution {
public:
    int t[101][201];
    int n;
    bool solve(string& s, int idx, int openCnt){
        //base case
        if(idx >= n){
            return openCnt == 0;
        }

        //memo
        if(t[idx][openCnt+100] != -1){
            return t[idx][openCnt+100];
        }

        bool isValid = false;
        if(s[idx] == '('){
            isValid |= solve(s, idx+1, openCnt + 1);
        } else if (s[idx] == ')' && openCnt > 0){
            isValid |= solve(s, idx+1, openCnt - 1);
        } else if(s[idx] == '*'){      //we have 3 cases
            //1st treat '*' as '('
            isValid |= solve(s, idx+1, openCnt + 1);
            //2nd treat '*' as '*'
            isValid |= solve(s, idx+1, openCnt);
            //3rd treat '*' as ')'
            if(openCnt > 0)
                isValid |= solve(s, idx+1, openCnt - 1);
        }
        return t[idx][openCnt+100] = isValid;
    }
    bool checkValidString(string s) {
        n = s.size();
        memset(t, -1, sizeof(t));
        return solve(s, 0, 0);
    }
};
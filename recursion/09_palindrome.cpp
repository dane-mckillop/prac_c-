class Solution {
public:
    bool isPalindrome(int x) {
        string input = to_string(x);
        int i = 0;
        int end = input.size()-1;

        return scanPalindrome(input, i, end);
    }

private:
    bool scanPalindrome(string& input, int i, int end) {
        // Base
        if (i >= end) {
            return true;
        }

        // Compare
        if (input[i] == input[end]) {
            return scanPalindrome(input, i+1, end-1);
        }
        else {
            return false;
        }
    }
};
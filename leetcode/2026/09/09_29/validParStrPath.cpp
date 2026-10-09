class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid){
        // Initialize
        int m = grid.size();
        int n = grid[0].size();
        vector<char> seen(m * n * (m + n), 0);

        // Odd length paths can never match
        if ((m + n - 1) % 2 != 0) return false;

        // True if a path exists where all parentheses match
        return walk(grid, 0, 0, 0, seen);
    }

private:
    int evaluateChar(char x, int open){
        if (x == '('){
            return open + 1;
        }
        return open - 1;
    }

    bool walk(vector<vector<char>>& grid, int r, int c, int open, vector<char>& seen){
        int m = grid.size();
        int n = grid[0].size();

        // Off the grid
        if (r >= m || c >= n) return false;

        open = evaluateChar(grid[r][c], open);

        // Close with no open
        if (open < 0) return false;

        // End of path: valid only if all matched
        if (r == m - 1 && c == n - 1) return open == 0;

        // Skip states already tried
        int key = (r * n + c) * (m + n) + open;
        if (seen[key]) return false;
        seen[key] = 1;

        // Try down, then right
        if (walk(grid, r + 1, c, open, seen)) return true;
        if (walk(grid, r, c + 1, open, seen)) return true;
        return false;
    }
};
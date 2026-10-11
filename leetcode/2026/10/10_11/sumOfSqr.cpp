class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        return scan(nums, 1, 0);
    }

private:
    int scan(const vector<int>& nums, int i, int acc) {
        if (i > nums.size()) return acc;
        if (nums.size() % i == 0) {
            acc += nums[i - 1] * nums[i - 1];
        }
        return scan(nums, i + 1, acc);
    }
};
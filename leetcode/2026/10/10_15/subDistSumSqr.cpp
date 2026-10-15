class Solution {
public:
    int sumCounts(vector<int>& nums) {
        return startAt(nums, 0);
    }

private:
    // Sum over all subarrays starting at i, i+1, ...
    int startAt(const vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;
        vector<bool> seen(101, false);
        return extend(nums, i, seen, 0) + startAt(nums, i + 1);
    }

    // Sum over subarrays nums[i..j], nums[i..j+1], ...
    int extend(const vector<int>& nums, int j, vector<bool>& seen, int distinct) {
        if (j >= nums.size()) return 0;
        if (!seen[nums[j]]) {
            seen[nums[j]] = true;
            ++distinct;
        }
        return distinct * distinct + extend(nums, j + 1, seen, distinct);
    }
};
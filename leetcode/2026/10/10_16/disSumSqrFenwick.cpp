/*
 * Fenwick tree (Binary Indexed Tree)
 *
 * A Fenwick tree stores an array in a compact form so that two things are
 * fast (O(log n)): changing one value, and getting a prefix sum (the sum of
 * the first k values). Each slot i stores the sum of a small block of
 * elements. The block's size is the lowest set bit of i, which is
 * (i & -i). Moving with i += (i & -i) walks "up" to every block that
 * contains position i (used to update), and i -= (i & -i) walks "down"
 * through the blocks that make up a prefix (used to sum).
 *
 * Here two Fenwick trees are combined (slopeTree and offsetTree) so we can
 * add 1 to a whole range and sum a whole range, both in O(log n).
 * That is exactly what the "distinct count of squares" sweep needs.
 */

class Solution {
    static const long long MOD = 1e9+7;

    int arrayLength;
    vector<long long> slopeTree;
    vector<long long> offsetTree;

    void update(vector<long long>& tree, int position, long long amount) {
        for (; position <= arrayLength; position += position & -position)
            tree[position] += amount;
    }

    long long prefix(const vector<long long>& tree, int position) {
        long long total = 0;
        for (; position > 0; position -= position & -position)
            total += tree[position];
        return total;
    }

    long long sumUpTo(int position) {
        return prefix(slopeTree, position) * position - prefix(offsetTree, position);
    }

    void addToRange(int rangeStart, int rangeEnd) {
        int left  = rangeStart + 1;
        int right = rangeEnd + 1;
        update(slopeTree,  left,      1);
        update(slopeTree,  right + 1, -1);
        update(offsetTree, left,      left - 1);
        update(offsetTree, right + 1, -right);
    }

    long long sumOfRange(int rangeStart, int rangeEnd) {
        return sumUpTo(rangeEnd + 1) - sumUpTo(rangeStart);
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        arrayLength = n;
        slopeTree.assign(n + 2, 0);
        offsetTree.assign(n + 2, 0);

        vector<int> last(100001, -1);
        long long cur = 0, ans = 0;

        for (int j = 0; j < n; ++j) {
            int rangeStart = last[nums[j]] + 1;
            int rangeEnd   = j;

            long long rangeSum = sumOfRange(rangeStart, rangeEnd);
            cur = (cur + 2 * (rangeSum % MOD) + (rangeEnd - rangeStart + 1)) % MOD;
            addToRange(rangeStart, rangeEnd);

            ans = (ans + cur) % MOD;
            last[nums[j]] = j;
        }
        return ans;
    }
};
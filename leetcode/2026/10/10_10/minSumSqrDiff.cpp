class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> cnt(100001, 0);
        countDiffs(nums1, nums2, 0, cnt);
        level(cnt, 100000, (long long)k1 + k2);
        return sumSquares(cnt, 1, 0);
    }

private:
    void countDiffs(const vector<int>& a, const vector<int>& b, int i, vector<long long>& cnt) {
        if (i >= a.size()) return;
        ++cnt[abs(a[i] - b[i])];
        countDiffs(a, b, i + 1, cnt);
    }

    void level(vector<long long>& cnt, int d, long long k) {
        if (d == 0 || k == 0) return;
        if (cnt[d] == 0) return level(cnt, d - 1, k);

        long long moved = min(k, cnt[d]);
        cnt[d] -= moved;
        cnt[d - 1] += moved;
        level(cnt, d - 1, k - moved);
    }

    long long sumSquares(const vector<long long>& cnt, int d, long long acc) {
        if (d > 100000) return acc;
        return sumSquares(cnt, d + 1, acc + cnt[d] * d * d);
    }
};
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sortArray(nums);
        return searchIndices(nums, target);
    }

private:
    // Selection-style swap sort (fine for n <= 100)
    void sortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] < nums[i]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }

    // Binary search for the first occurrence, then collect all matches
    vector<int> searchIndices(vector<int>& nums, int target) {
        vector<int> result;
        int lo = 0, hi = nums.size(); 
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }

        for (int i = lo; i < nums.size() && nums[i] == target; ++i) {
            result.push_back(i);
        }
        return result;
    }
};
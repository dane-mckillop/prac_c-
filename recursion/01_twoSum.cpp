/**
 * You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * You can return the answer in any order.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};

        scanNums(nums, result, 0, 1, target);
        
        return result;
    }

private:
    void scanNums(vector<int>& nums, vector<int>& result, int head, int tail, int target) {
        // Base: target reached
        if (nums[head] + nums[tail] == target) {
            result = {head, tail};
            return;
        }
        
        if (tail < nums.size()-1) {
            scanNums(nums, result, head, tail + 1, target);
        } 
        else if (head < nums.size()-1) {
            scanNums(nums, result, head + 1, head + 2, target);
        }
        return;
    }
};
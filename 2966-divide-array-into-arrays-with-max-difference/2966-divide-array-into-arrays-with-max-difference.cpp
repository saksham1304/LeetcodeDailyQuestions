#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> result;

        // Sort the array
        sort(nums.begin(), nums.end());

        // Iterate through the array in groups of 3
        for (int i = 0; i < n; i += 3) {
            // Check if the difference between the first and last elements in the group is less than or equal to k
            if (i + 2 < n && nums[i + 2] - nums[i] <= k) {
                result.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else {
                // If any group doesn't satisfy the condition, return an empty array
                return {};
            }
        }

        return result;
    }
};

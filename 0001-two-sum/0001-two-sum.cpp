#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // Check if the complement is already in the map
            if (mp.find(complement) != mp.end()) {
                // Return the indices of the two numbers
                return {mp[complement], i};
            }

            // Insert the current number and its index into the map
            mp[nums[i]] = i;
        }

        // No solution found, return an empty vector
        return {};
    }
};

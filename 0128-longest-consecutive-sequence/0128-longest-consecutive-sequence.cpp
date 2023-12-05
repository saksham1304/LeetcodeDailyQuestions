#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int longestStreak = 1;
        int currentStreak = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    // Increment streak for consecutive numbers
                    currentStreak++;
                } else {
                    // Reset streak for non-consecutive numbers
                    longestStreak = std::max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        // Handle the case where the longest streak ends at the last element
        return std::max(longestStreak, currentStreak);
    }
};

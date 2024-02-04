#include <vector>
#include <algorithm>
#include <sstream>

class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            // Convert numbers to strings and concatenate them in two orders
            std::string order1 = std::to_string(a) + std::to_string(b);
            std::string order2 = std::to_string(b) + std::to_string(a);
            
            // Compare the concatenated strings to determine the order
            return order1 > order2;
        });

        // Handle the case where all numbers are 0
        if (nums[0] == 0) {
            return "0";
        }

        // Concatenate the sorted numbers to form the largest number
        std::ostringstream result;
        for (int num : nums) {
            result << num;
        }

        return result.str();
    }
};

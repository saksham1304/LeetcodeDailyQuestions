#include <vector>
#include <cstdlib>

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> f;

        for (int i = 0; i < n; i++) {
            int suml = 0;
            int sumr = 0;

            // Calculate the sum of elements on the left side
            for (int j = 0; j < i; j++) {
                suml += nums[j];
            }

            // Calculate the sum of elements on the right side
            for (int k = i + 1; k < n; k++) {
                sumr += nums[k];
            }

            f.push_back(std::abs(suml - sumr));
        }

        return f;
    }
};

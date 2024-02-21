#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // Keep track of the farthest index we can reach

        for (int i = 0; i < nums.size(); i++) {
            // If we cannot reach this index, return false
            if (i > maxReach) {
                return false;
            }

            // Update maxReach if we can reach farther
            maxReach = max(maxReach, i + nums[i]);

            // If we can reach the last index, return true
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }

        return false; // We couldn't reach the end
    }
};

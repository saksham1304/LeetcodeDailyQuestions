#include <vector>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;

        // Count occurrences of each number
        for (int num : nums) {
            mp[num]++;
        }

        // Find the number with only one occurrence
        for (auto it : mp) {
            if (it.second == 1) {
                return it.first;
            }
        }

        // No single number found (you may want to handle this case differently)
        return -1; 
    }
};

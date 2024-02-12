#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        // Count occurrences of each element
        for (int num : nums) {
            mp[num]++;
        }
        
        // Find the majority element
        int majorityCount = nums.size() / 2;
        for (auto& pair : mp) {
            if (pair.second > majorityCount) {
                return pair.first;
            }
        }
        
        // Shouldn't reach here due to the assumption of a majority element always existing
        return -1;
    }
};

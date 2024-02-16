#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
        std::unordered_map<int, int> mp;
        for (auto num : arr) {
            mp[num]++;
        }
        
        vector<int> freq;
        for (const auto& pair : mp) {
            freq.push_back(pair.second);
        }
        
        sort(freq.begin(), freq.end());
        
        int removed = 0;
        int uniqueCount = freq.size();
        for (int i = 0; i < freq.size(); i++) {
            if (removed + freq[i] <= k) {
                removed += freq[i];
                uniqueCount--;
            } else {
                break;
            }
        }
        
        return uniqueCount;
    }
};

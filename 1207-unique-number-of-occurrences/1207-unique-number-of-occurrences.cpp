#include <vector>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_set<int> uniqueSet;
        std::unordered_set<int> counts;

        for (int num : arr) {
            if (uniqueSet.count(num) == 0) {
                uniqueSet.insert(num);

                int count = std::count(arr.begin(), arr.end(), num);

                if (counts.count(count) != 0) {
                    return false;
                }

                counts.insert(count);
            }
        }

        return true;
    }
};

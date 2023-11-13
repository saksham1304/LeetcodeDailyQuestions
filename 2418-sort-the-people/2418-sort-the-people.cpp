#include <vector>
#include <algorithm> // for std::sort

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        std::vector<std::pair<int, std::string>> data; // Pairing heights with names
        for (int i = 0; i < heights.size(); ++i) {
            data.push_back({heights[i], names[i]});
        }

        // Sort in decreasing order based on heights
        std::sort(data.begin(), data.end(), std::greater<std::pair<int, std::string>>());

        std::vector<std::string> result;
        for (const auto& pair : data) {
            result.push_back(pair.second); // Extracting names from the sorted pairs
        }

        return result;
    }
};

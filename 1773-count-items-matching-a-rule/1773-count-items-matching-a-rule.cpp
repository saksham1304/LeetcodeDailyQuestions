#include <vector>
#include <string>

class Solution {
public:
    int countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey, std::string ruleValue) {
        int count = 0;
        int ruleIndex = 0;  // 0 for "type", 1 for "color", 2 for "name"

        if (ruleKey == "color") {
            ruleIndex = 1;
        } else if (ruleKey == "name") {
            ruleIndex = 2;
        }

        for (const auto& item : items) {
            if (item[ruleIndex] == ruleValue) {
                count++;
            }
        }

        return count;
    }
};

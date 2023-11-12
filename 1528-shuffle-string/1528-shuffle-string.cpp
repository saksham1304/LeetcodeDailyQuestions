#include <string>
#include <vector>

class Solution {
public:
    std::string restoreString(string s, vector<int>& indices) {
        string result(s.length(), ' '); // Initialize result with the same length as s

        for (int i = 0; i < indices.size(); i++) {
            result[indices[i]] = s[i];
        }

        return result;
    }
};

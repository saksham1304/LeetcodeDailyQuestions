#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }

        std::vector<int> charCount(26, 0); // Assuming only lowercase English letters

        // Increment counts for characters in string s
        for (char c : s) {
            charCount[c - 'a']++;
        }

        // Decrement counts for characters in string t
        for (char c : t) {
            charCount[c - 'a']--;
            if (charCount[c - 'a'] < 0) {
                return false; // More occurrences of character c in t than in s
            }
        }

        return true;
    }
};

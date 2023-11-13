#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string sortVowels(std::string s) {
        std::vector<char> vowels;
        std::string result = s;

        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        std::sort(vowels.begin(), vowels.end());

        int vowelIndex = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isVowel(s[i])) {
                result[i] = vowels[vowelIndex++];
            }
        }

        return result;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

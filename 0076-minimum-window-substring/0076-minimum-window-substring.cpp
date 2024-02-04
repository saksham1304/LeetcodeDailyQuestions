#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        unordered_map<char, int> targetCount;

        for (char c : t) {
            targetCount[c]++;
        }

        int left = 0, right = 0;
        int requiredChars = targetCount.size();
        int formedChars = 0;
        int minLen = INT_MAX;
        int minLeft = 0;

        unordered_map<char, int> windowCount;

        while (right < s.length()) {
            // Expand the window
            char c = s[right];
            windowCount[c]++;
            if (targetCount.find(c) != targetCount.end() && windowCount[c] == targetCount[c]) {
                formedChars++;
            }

            // Contract the window
            while (formedChars == requiredChars) {
                // Update the minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                char leftChar = s[left];
                windowCount[leftChar]--;
                if (targetCount.find(leftChar) != targetCount.end() && windowCount[leftChar] < targetCount[leftChar]) {
                    formedChars--;
                }

                left++;
            }

            // Move the right pointer to expand the window
            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(minLeft, minLen);
    }
};

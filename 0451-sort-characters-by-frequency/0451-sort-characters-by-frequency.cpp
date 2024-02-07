#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Count the frequency of each character
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        
        // Sort characters based on their frequency in descending order
        sort(s.begin(), s.end(), [&](char a, char b) {
            if (charCount[a] == charCount[b]) {
                return a < b; // If frequencies are same, sort by character order
            }
            return charCount[a] > charCount[b]; // Sort by frequency
        });
        
        return s;
    }
};

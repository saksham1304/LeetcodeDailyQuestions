#include <unordered_map>
#include <string>
#include <vector>
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
        vector<pair<char, int>> sorted_chars(charCount.begin(), charCount.end());
        sort(sorted_chars.begin(), sorted_chars.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        
        // Build the sorted string
        string sorted_string;
        for (const auto& p : sorted_chars) {
            sorted_string += string(p.second, p.first);
        }
        
        return sorted_string;
    }
};



#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& ch) {
        unordered_map<string, vector<string>> anagramGroups;
        
        // Iterate through each string in the input vector
        for (const string& s : ch) {
            // Create a key by sorting the characters in the string
            string key = s;
            sort(key.begin(), key.end());
            
            // Add the string to the corresponding group
            anagramGroups[key].push_back(s);
        }
        
        // Convert the map to vector
        vector<vector<string>> result;
        for (const auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

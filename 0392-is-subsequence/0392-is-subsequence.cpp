#include <vector>
#include <string>

class Solution {
public:
    #include <iostream>
#include <string>

bool isSubsequence(std::string s, std::string t) {
    int i = 0, j = 0;

    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    // If i reaches the end of s, then s is a subsequence of t
    return i == s.size();
}

};

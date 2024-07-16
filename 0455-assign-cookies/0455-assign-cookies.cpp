#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        int count = 0;
        
        // Sort the arrays
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        for (int i = 0, j = 0; i < g.size() && j < s.size();) {
            if (g[i] <= s[j]) {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};
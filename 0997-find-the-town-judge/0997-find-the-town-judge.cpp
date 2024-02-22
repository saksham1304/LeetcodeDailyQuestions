#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Create trust counts for each person
        unordered_map<int, int> trustCounts;
        unordered_map<int, bool> trustsSomeone;
        
        for (const auto& t : trust) {
            int a = t[0];
            int b = t[1];
            trustCounts[b]++;
            trustsSomeone[a] = true;
        }
        
        // Find the person who is trusted by everyone else
        for (int i = 1; i <= n; ++i) {
            if (trustCounts[i] == n - 1 && !trustsSomeone[i]) {
                return i;
            }
        }
        
        return -1;
    }
};

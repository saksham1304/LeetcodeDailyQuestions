#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        
        int i = 1;
        while (true) {
            if (mp.find(i) == mp.end()) {
                return i;
            }
            i++;
        }
    }
};

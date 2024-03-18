#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort the intervals based on their end points
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Initialize variables
        int arrows = 0;
        long long end_point = LONG_MIN; // Using long long to avoid overflow
        
        // Iterate through the sorted intervals
        for (const auto& interval : points) {
            // If there is no overlap, shoot another arrow
            if (interval[0] > end_point) {
                arrows++;
                end_point = interval[1]; // Update the current end point
            }
        }
        
        return arrows;
    }
};

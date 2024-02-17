#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& height, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to store height differences
        
        for (int i = 0; i < height.size() - 1; ++i) {
            int diff = height[i + 1] - height[i];
            if (diff > 0) {
                pq.push(diff);
                if (pq.size() > ladders) {
                    bricks -= pq.top(); // Use bricks to cover the smallest height difference
                    pq.pop();
                    if (bricks < 0) return i; // If bricks become negative, cannot go further
                }
            }
        }
        
        return height.size() - 1; // If all buildings can be reached
    }
};

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        queue<int> q;

        // Enqueue all single-digit numbers
        for (int i = 1; i <= 9; i++) {
            q.push(i);
        }

        // BFS to generate sequential digits
        while (!q.empty()) {
            int num = q.front();
            q.pop();

            if (num >= low && num <= high) {
                result.push_back(num);
            }

            int lastDigit = num % 10;

            // Add the next sequential digit if it's less than or equal to 9
            if (lastDigit < 9) {
                q.push(num * 10 + lastDigit + 1);
            }
        }

        return result;
    }
};

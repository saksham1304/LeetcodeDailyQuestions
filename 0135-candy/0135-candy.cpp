#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> candies(n, 1);

        // Traverse from left to right to make sure a child with a higher rating gets more candies than the one with a lower rating on the left
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Traverse from right to left to make sure a child with a higher rating gets more candies than the one with a lower rating on the right
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        // Calculate the total sum of candies
        int sum = 0;
        for (int candy : candies) {
            sum += candy;
        }

        return sum;
    }
};

#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& a) {
        std::vector<int> result;
        int n = a.size();

        // Initialize an array to store the product of all elements to the left of each index
        std::vector<int> leftProducts(n, 1);

        // Initialize an array to store the product of all elements to the right of each index
        std::vector<int> rightProducts(n, 1);

        // Compute the product of all elements to the left of each index
        int leftProduct = 1;
        for (int i = 1; i < n; i++) {
            leftProduct *= a[i - 1];
            leftProducts[i] = leftProduct;
        }

        // Compute the product of all elements to the right of each index
        int rightProduct = 1;
        for (int i = n - 2; i >= 0; i--) {
            rightProduct *= a[i + 1];
            rightProducts[i] = rightProduct;
        }

        // Multiply the corresponding left and right products to get the final result
        for (int i = 0; i < n; i++) {
            result.push_back(leftProducts[i] * rightProducts[i]);
        }

        return result;
    }
};

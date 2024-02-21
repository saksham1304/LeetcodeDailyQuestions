class Solution {
public:
    bool isHappy(int n) {
        // Set to store visited numbers to detect cycles
        unordered_set<int> seen;

        // Continue loop until either n becomes 1 (happy) or we detect a cycle
        while (n != 1 && !seen.count(n)) {
            seen.insert(n); // Add current number to the set of seen numbers
            int sum = 0;
            // Calculate the sum of squares of digits
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum; // Update n with the sum
        }

        // If n is 1, it's a happy number, otherwise, it's not
        return n == 1;
    }
};

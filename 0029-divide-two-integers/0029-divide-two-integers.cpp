#include <limits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle division by zero
        if (divisor == 0) {
            return INT_MAX; // Return maximum integer value as a signal for division by zero
        }

        // Handle overflow cases
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow can occur only when dividing INT_MIN by -1
        }

        // Perform division
        long long quotient = static_cast<long long>(dividend) / divisor;

        // Check for overflow
        if (quotient < INT_MIN || quotient > INT_MAX) {
            return INT_MAX; // Return maximum integer value in case of overflow
        }

        return static_cast<int>(quotient);
    }
};

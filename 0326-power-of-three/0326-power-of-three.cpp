class Solution {
public:
    bool isPowerOfThree(int n) {
     if (n <= 0) {
        return false;
    }
    double exponent = log10(n) / log10(3);
    return exponent == floor(exponent);
    }
};
class Solution {
public:
int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX); // Initialize a vector to store the least number of perfect squares for each number from 0 to n
    
    dp[0] = 0; // Base case: for 0, the least number of perfect squares is 0
    
    // Iterate from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Try all possible perfect squares less than or equal to i
        for (int j = 1; j * j <= i; ++j) {
            // Update dp[i] by considering the current perfect square
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    
    // The result is stored at dp[n]
    return dp[n];
}
};
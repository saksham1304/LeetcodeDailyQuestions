class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0); // dp array to store the minimum cuts
        vector<vector<bool>> palindrome(n, vector<bool>(n, false)); // table to store palindrome information

        // Preprocess the palindrome table
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            int mincost = INT_MAX;
            for (int j = i; j < n; ++j) {
                if (palindrome[i][j]) {
                    mincost = min(mincost, 1 + dp[j + 1]);
                }
            }
            dp[i] = mincost;
        }

        return dp[0] - 1; // subtract 1 because the last cut is not needed
    }
};

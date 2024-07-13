class Solution {
public:
    int func(int n, vector<vector<int>>& t, vector<vector<int>>& dp) {
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = t[n-1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = t[i][j] + dp[i + 1][j];
                int diag = t[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return func(n, t, dp);
    }
};

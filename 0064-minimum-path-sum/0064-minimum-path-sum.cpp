class Solution {
public:
    int func(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                } else {
                    int up = INT_MAX, left = INT_MAX;
                    if (i > 0) up = grid[i][j] + dp[i-1][j];
                    if (j > 0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return func(m, n, grid, dp);
    }
};

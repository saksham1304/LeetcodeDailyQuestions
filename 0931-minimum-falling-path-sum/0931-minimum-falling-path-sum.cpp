class Solution {
public:
    int func(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& mat) {
        // Initialize the dp array
        dp.resize(m, vector<int>(n, INT_MAX));
        
        // Initialize the first row of dp
        for (int j = 0; j < n; j++) dp[0][j] = mat[0][j];
        
        // Fill the dp array
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = mat[i][j] + dp[i-1][j];
                int ld = (j > 0) ? mat[i][j] + dp[i-1][j-1] : INT_MAX;
                int rd = (j < n-1) ? mat[i][j] + dp[i-1][j+1] : INT_MAX;
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        
        // Find the minimum value in the last row of dp
        int mini = dp[m-1][0];
        for (int j = 1; j < n; j++) mini = min(mini, dp[m-1][j]);
        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp;
        return func(m, n, dp, mat);
    }
};

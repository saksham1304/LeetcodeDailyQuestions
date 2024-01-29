class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;

        // Prefix sum matrix
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = matrix[i - 1][j - 1] +
                                  prefixSum[i - 1][j] +
                                  prefixSum[i][j - 1] -
                                  prefixSum[i - 1][j - 1];
            }
        }

        // Iterate through all possible pairs of rows and columns
        for (int row1 = 1; row1 <= m; row1++) {
            for (int row2 = row1; row2 <= m; row2++) {
                for (int col1 = 1; col1 <= n; col1++) {
                    for (int col2 = col1; col2 <= n; col2++) {
                        int currentSum = prefixSum[row2][col2] -
                                         prefixSum[row1 - 1][col2] -
                                         prefixSum[row2][col1 - 1] +
                                         prefixSum[row1 - 1][col1 - 1];
                        if (currentSum == target) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};

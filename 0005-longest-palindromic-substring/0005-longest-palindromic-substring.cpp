class Solution {
public:
    string longestPalindrome(string text1) {
        int n = text1.size();
        if (n == 0) return "";

        string text2 = text1;
        reverse(text2.begin(), text2.end());
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxLength = 0;
        int endIndex = 0;

        // Build the dp array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    
                    // Check if the substring is palindromic
                    int startIdxInOrig = i - dp[i][j];
                    int startIdxInRev = n - j;
                    if (startIdxInOrig == startIdxInRev) {
                        if (dp[i][j] > maxLength) {
                            maxLength = dp[i][j];
                            endIndex = i - 1;
                        }
                    }
                }
            }
        }

        return text1.substr(endIndex - maxLength + 1, maxLength);
    }
};

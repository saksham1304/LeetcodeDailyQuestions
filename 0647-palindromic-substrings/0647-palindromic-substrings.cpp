class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        // Single characters are palindromes
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
            ++count;
        }

        // Check for substrings of length 2
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ++count;
            }
        }

        // Check for substrings of length greater than 2
        for (int length = 3; length <= s.size(); ++length) {
            for (int i = 0; i <= s.size() - length; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ++count;
                }
            }
        }

        return count;
    }
};

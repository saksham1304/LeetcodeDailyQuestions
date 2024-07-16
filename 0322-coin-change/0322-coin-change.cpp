#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amt) {
        int n = coins.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(amt + 1, INT_MAX));
        
        // Initialization
        for (int t = 0; t <= amt; ++t) {
            if (t % coins[0] == 0) dp[0][t] = t / coins[0];
            else dp[0][t] = 1e9;
        }
        
        // Fill DP table
        for (int ind = 1; ind < n; ++ind) {
            for (int tar = 0; tar <= amt; ++tar) {
                int nottake = dp[ind - 1][tar];
                int take = INT_MAX;
                if (coins[ind] <= tar) take = 1 + dp[ind][tar - coins[ind]];
                dp[ind][tar] = std::min(take, nottake);
            }
        }
        
        int result = dp[n - 1][amt];
        return result >= 1e9 ? -1 : result;
    }
};

#include <vector>

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }

        int totalSum = 0;

        // Calculate sum for all subarrays with odd lengths
        for (int len = 1; len <= n; len += 2) {
            for (int i = 0; i <= n - len; ++i) {
                int subarraySum = prefixSum[i + len] - prefixSum[i];
                totalSum += subarraySum;
            }
        }

        return totalSum;
    }
};

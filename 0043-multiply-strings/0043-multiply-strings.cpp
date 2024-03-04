#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> result(n1 + n2, 0);

        // Multiply each digit and sum them up in the result vector
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j] += sum / 10;
                result[i + j + 1] = sum % 10;
            }
        }

        // Convert result vector to string
        string res;
        for (int num : result) {
            if (!(res.empty() && num == 0)) {
                res.push_back(num + '0');
            }
        }
        return res.empty() ? "0" : res;
    }
};

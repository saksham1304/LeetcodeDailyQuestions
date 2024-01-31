#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& t) {
        int n = t.size();
        std::vector<int> result(n, 0);
        std::stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && t[i] > t[s.top()]) {
                int j = s.top();
                s.pop();
                result[j] = i - j;
            }
            s.push(i);
        }

        return result;
    }
};

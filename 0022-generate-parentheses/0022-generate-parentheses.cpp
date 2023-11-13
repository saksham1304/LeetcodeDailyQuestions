#include <vector>
#include <stack>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generateParenthesisHelper(result, "", n, n);
        return result;
    }

private:
    void generateParenthesisHelper(std::vector<std::string>& result, std::string current, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }

        if (left > 0) {
            generateParenthesisHelper(result, current + '(', left - 1, right);
        }
        if (right > left) {
            generateParenthesisHelper(result, current + ')', left, right - 1);
        }
    }
};

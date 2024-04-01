#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool wordStarted = false;

        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s.at(i);
            if (ch != ' ') {
                wordStarted = true;
                count++;
            } else if (wordStarted) {
                break;
            }
        }

        return count;
    }
};

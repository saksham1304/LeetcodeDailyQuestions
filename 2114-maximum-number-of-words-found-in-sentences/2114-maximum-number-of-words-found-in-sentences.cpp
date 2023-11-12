#include <vector>
#include <string>

class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        vector<int> lengths;
        for (int i = 0; i < s.size(); i++) {
            string str = s.at(i);
            int count = 0;
            for (int j = 0; j < str.size(); j++) {
                if (str.at(j) == ' ') {
                    count++;
                }
            }
            lengths.push_back(count + 1);
        }

        int max_length = lengths[0];
        for (int i = 0; i < lengths.size(); i++) {
            if (lengths[i] > max_length) {
                max_length = lengths[i];
            }
        }
        return max_length;
    }
};

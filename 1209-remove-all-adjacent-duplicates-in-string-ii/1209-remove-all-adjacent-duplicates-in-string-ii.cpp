#include <string>
#include <stack>

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (char ch : s) {
            if (!st.empty() && st.top().first == ch) {
                if (++st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({ch, 1});
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result = string(st.top().second, st.top().first) + result;
            st.pop();
        }
        return result;
    }
};

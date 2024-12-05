class Solution {
public:
    std::unordered_map<std::string, int> hash;

    int numDecodings(std::string s) {
        return rec(s);
    }

private:
    int rec(const std::string& s) {
        if (hash.find(s) != hash.end()) return hash[s];
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        if (s.length() == 0) return 1;

        int res = rec(s.substr(1));

        if (std::stoi(s.substr(0, 2)) <= 26) {
            res += rec(s.substr(2));
        }

        hash[s] = res;
        return res;
    }
};
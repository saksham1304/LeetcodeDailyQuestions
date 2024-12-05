class Solution {
public:
    bool fun(int i, int j, string str){
        if(i > j) return true;
        if(str[i] != str[j]) return false;
        return fun(i+ 1, j - 1, str);
    }

    bool isPalindrome(string s) {
        string str = "";
        int n = s.size();
        for(int i = n - 1;i >= 0;i--){
            if(isdigit(s[i])){
                str += s[i];
            }
            if(s[i] > 64 && s[i] < 91){
                str += tolower(s[i]);
            }
            else if(s[i] > 96 && s[i] < 123){
                str += s[i];
            }
            else continue;
        }
        int i = 0;
        int j = n - 1;
        // return fun(i, j, str);
        string a = str;
        reverse(a.begin(), a.end());
        return a == str;
    }
};
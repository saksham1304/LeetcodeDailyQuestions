class Solution {
public:
    string defangIPaddr(string address) {
        int l = address.size();
        for(int i = 0; i < l; i++) {
            char ch = address.at(i);
            if(ch == '.') {
                address.replace(i, 1, "[.]");
                // Increment 'i' by 2 to skip over the inserted "[.]".
                i += 2;
                l += 2; // Update the length of the string.
            }
        }
        return address;
    }
};

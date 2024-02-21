class Solution {
public:
    int rangeBitwiseAnd(int a, int b) {
        int shiftcount = 0;
      while(a != b and a > 0) {
          shiftcount++;
          a = a >> 1; 
          b = b >> 1;
    }
      return int64_t(a << shiftcount);

    }
};
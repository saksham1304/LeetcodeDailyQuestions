class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>mpp(256,-1);
        int l=0,r=0, maxlen=0;
        while(r<n){
            if(mpp[s[r]]!=-1){
                if(mpp[s[r]]>=l){
                    l=mpp[s[r]]+1;
                }
            }
         int len=r-l+1;
            maxlen=max(maxlen,len);
            mpp[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};
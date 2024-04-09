class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;int r=0;int maxlen=0;
        vector<int>mpp(256,-1);
        while(r<s.size()){
            if(mpp[s[r]]!=-1){
                if(mpp[s[r]]>=l){
                    l=mpp[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            mpp[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};
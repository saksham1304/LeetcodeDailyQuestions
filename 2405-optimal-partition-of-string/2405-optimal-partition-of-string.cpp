class Solution {
public:
    int partitionString(string s) {
        vector<int>lastseen(26,-1);
        int count=0;
        int scs=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(lastseen[ch-'a']>=scs){
                count++;
                scs=i;
            }
            lastseen[ch-'a']=i;
        }
        return count+1;
    }
};
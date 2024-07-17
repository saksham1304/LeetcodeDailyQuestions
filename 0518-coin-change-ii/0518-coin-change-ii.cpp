class Solution {
public:
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amt+1,0));
        for(int t=0;t<=amt;t++) dp[0][t]=(t%coins[0]==0);
        for(int i=1;i<n;i++){
            for(int t=0;t<=amt;t++){
                int nottake=dp[i-1][t];
                int take=0;
                if(coins[i]<=t)take=dp[i][t-coins[i]];
                dp[i][t]=take+nottake;
            }
        }
        return dp[n-1][amt];
    }
};
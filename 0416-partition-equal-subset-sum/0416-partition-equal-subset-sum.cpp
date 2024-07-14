class Solution {
public:
    bool func(int n, int tar,vector<int>&arr, vector<vector<bool>>&dp){
        for(int i=0;i<n;i++)dp[i][0]=true;
        if (arr[0] <= tar)dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=tar;target++){
                bool nottake=dp[i-1][target];
                bool take=false;
                if(target>=arr[i])take=dp[i-1][target-arr[i]];
                dp[i][target]=take|nottake;
            }
        }
        return  dp[n-1][tar];
    }
    bool canPartition(vector<int>& nums) {
    int n=nums.size();
       
        int totsum=0;
        for(int i=0;i<n;i++){
            totsum+=nums[i];
        }
        if(totsum%2)return false;
        int target=totsum/2;
         vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        return func(n,target,nums,dp);
        
    }
};
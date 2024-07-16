class Solution {
public:
    int mod=(int)1e9;
    int findWays(vector<int>&nums , int target){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        if(nums[0]==0 )dp[0][0]=2;
        else dp[0][0]=1;
        if(nums[0]!=0 && nums[0]<=target)dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=target;tar++){
                int nottake=dp[i-1][tar];
                int take=0;
                if(nums[i]<=tar)take=dp[i-1][tar-nums[i]];
                dp[i][tar]=(take+nottake)%mod;
            }
        }
        return dp[n-1][target];
    }
   
    int findTargetSumWays(vector<int>& arr, int target) {
        int totSum = 0;
        int n=arr.size();
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWays(arr, (totSum - target) / 2);

    }
};
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>f={};
        for(int i=0;i<nums.size();i++){
            f.push_back(nums[nums[i]]);
        }
        return f;
    }
};
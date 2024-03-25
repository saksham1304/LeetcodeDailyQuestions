class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto& it:mp){
            if(it.second>1){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
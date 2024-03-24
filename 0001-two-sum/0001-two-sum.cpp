#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j){continue;}
                if(nums[j]+nums[i]==target){
                result.push_back(j);
                result.push_back(i);
                    return result;
            }
            }
        }
        return {};
    }
};

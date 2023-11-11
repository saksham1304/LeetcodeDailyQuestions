class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>dub;
         vector<int>f;
        for(int i=0;i<nums.size();i++){
            dub.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            f.push_back(nums[i]);
        }
        for(int i=0;i<dub.size();i++){
            f.push_back(dub[i]);
        }
        return f;
    }
};
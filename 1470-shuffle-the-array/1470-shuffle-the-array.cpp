class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
         vector<int> result;
        
        // Iterate up to n because you want to consider only the first half of the original vector
        for(int i = 0; i < n; i++) {
            // Add the i-th element from the first half
            result.push_back(nums[i]);
            
            // Add the i-th element from the second half
            result.push_back(nums[i + n]);
        }
        
        return result;
    }
};
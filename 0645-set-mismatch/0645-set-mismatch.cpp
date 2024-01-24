class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> f;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    // Duplicate found, add it to the result vector
                    f.push_back(nums[i]);
                    break;  // Break to avoid adding the same duplicate multiple times
                }
            }
        }

        // Find the missing number
        for (int i = 1; i <= nums.size(); i++) {
            if (find(nums.begin(), nums.end(), i) == nums.end()) {
                f.push_back(i);
                break;  // Break after finding the missing number
            }
        }

        return f;
    }
};
